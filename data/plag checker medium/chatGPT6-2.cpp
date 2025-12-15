#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node that points to the head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Set two pointers: slow and fast
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast pointer n+1 steps ahead to create a gap of n nodes between fast and slow
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }

        // Move both fast and slow pointers until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Now slow points to the node before the target node, so skip the nth node
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;

        // Free the memory of the deleted node
        delete nodeToDelete;

        // Return the head of the updated list
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Example usage
int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original List: ";
    printList(head);

    Solution solution;
    int n = 2;
    head = solution.removeNthFromEnd(head, n);

    std::cout << "List after removing " << n << "th node from the end: ";
    printList(head);

    return 0;
}
