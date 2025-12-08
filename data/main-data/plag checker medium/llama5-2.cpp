// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Initialize two pointers
        ListNode* first = head;
        ListNode* second = head;
        
        // Advance 'first' pointer so that the gap between 'first' and 'second' is n nodes apart
        for (int i = 1; i <= n; i++) {
            first = first->next;
        }
        
        // If first is NULL, that means we need to delete the head
        if (!first) {
            return head->next;
        }
        
        // Move first to the end, maintaining the gap
        while (first->next) {
            first = first->next;
            second = second->next;
        }
        
        // Remove the nth node from the end
        second->next = second->next->next;
        
        return head;
    }
};