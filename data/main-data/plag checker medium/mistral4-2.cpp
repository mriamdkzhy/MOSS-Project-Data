#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Advance the first pointer n steps ahead
        for (int i = 0; i <= n; ++i) {
            if (first == NULL) return NULL; // In case n is larger than the length of the list
            first = first->next;
        }

        // Move both pointers until the first pointer reaches the end
        while (first != NULL) {
            first = first->next;
            second = second->next;
        }

        // second is now pointing to the node just before the node to be deleted
        ListNode* temp = second->next;
        second->next = second->next->next;

        delete temp; // Free the memory of the deleted node

        ListNode* result = dummy->next;
        delete dummy; // Free the memory of the dummy node

        return result;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    int n = 2; // Remove the 2nd node from the end
    head = solution.removeNthFromEnd(head, n);

    // Print the modified list
    printList(head);

    // Free the memory of the linked list
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
