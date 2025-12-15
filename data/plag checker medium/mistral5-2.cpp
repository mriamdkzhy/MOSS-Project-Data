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

        // Advance the first pointer by n+1 steps to create a gap of n nodes
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

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != NULL
