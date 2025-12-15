#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to handle edge cases easily (e.g., removing the head node)
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move the fast pointer n steps ahead
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        // Move both fast and slow pointers until fast reaches the end
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node from the end
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete; // Free the memory of the deleted node

        // Return the new head (dummy->next)
        ListNode* newHead = dummy->next;
        delete dummy; // Free the dummy node
        return newHead;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original list: ";
    printList(head);

    Solution solution;
    int n = 2;
    head = solution.removeNthFromEnd(head, n);

    std::cout << "List after removing " << n << "th node from the end: ";
    printList(head);

    return 0;
}
