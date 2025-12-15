/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Initialize two pointers, p1 and p2, to the head of the list
        ListNode* p1 = head;
        ListNode* p2 = head;
        
        // Move p2 n steps ahead
        for (int i = 0; i < n; i++) {
            p2 = p2->next;
        }
        
        // If p2 is NULL, it means we need to remove the head
        if (!p2) {
            return head->next;
        }
        
        // Move both pointers until p2 reaches the end
        while (p2->next) {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        // Remove the nth node from the end
        p1->next = p1->next->next;
        
        return head;
    }
};