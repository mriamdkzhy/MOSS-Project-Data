// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Initialize two pointers, both pointing at the head
        ListNode* first = head;
        ListNode* second = head;
        
        // Move 'first' pointer so that the gap between 'first' and 'second' is n nodes apart
        for (int i = 0; i < n; i++) {
            first = first->next;
        }
        
        // If 'first' is NULL, that means we need to remove the head
        if (!first) {
            return head->next;
        }
        
        // Move both pointers one step at a time until 'first' reaches the end
        while (first->next) {
            first = first->next;
            second = second->next;
        }
        
        // Remove the nth node from the end
        second->next = second->next->next;
        
        return head;
    }
};