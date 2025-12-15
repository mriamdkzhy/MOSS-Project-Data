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

        // Move the first pointer n+1 steps ahead
        for (int i = 0; i <= n; ++i) {
            first = first->next;
        }

        // Move both pointers until the first pointer reaches the end
        while (first != NULL) {
            first = first->next;
            second = second->next;
        }

        // Remove the nth node from the end
        ListNode* temp = second->next;
        second->next = second->next->next;
        delete temp;

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

// Helper function to print the linked list
void printList(ListNode* node) {
    while (node != NULL) {
        std::cout << node->val << " -> ";
        node = node->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;
    Solution solution;
    ListNode* newHead = solution.removeNthFromEnd(head, n);

    // Printing the modified list
    printList(newHead);

    // Cleaning up the memory
    while (newHead != NULL) {
        ListNode* temp = newHead;
        newHead = newHead->next;
        delete temp;
    }

    return 0;
}
