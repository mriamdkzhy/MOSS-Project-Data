// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to simplify edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Initialize two pointers, one that is n nodes ahead
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Move the first pointer n nodes ahead
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }

        // Move both pointers until the first pointer reaches the end
        while (first != NULL) {
            first = first->next;
            second = second->next;
        }

        // Remove the nth node from the end
        second->next = second->next->next;

        // Return the beginning of the list
        return dummy->next;
    }
};