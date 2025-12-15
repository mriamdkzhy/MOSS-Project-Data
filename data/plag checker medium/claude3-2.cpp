/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Edge case: if the list is empty or n is 0
        if (!head || n == 0) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;
        
        // Move first pointer n nodes ahead
        for (int i = 0; i < n; i++) {
            if (!first) return head;  // n is larger than the length of the list
            first = first->next;
        }
        
        // Move both pointers until first reaches the end
        while (first->next) {
            first = first->next;
            second = second->next;
        }
        
        // Remove the nth node from the end
        ListNode* temp = second->next;
        second->next = second->next->next;
        delete temp;
        
        // Return the head of the modified list
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};