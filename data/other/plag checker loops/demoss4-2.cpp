class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        // Replacing 'if' with 'switch' statement
        switch (head->val > 4) {
            case true:
                head = new ListNode(0, head);
                break;
        }
        ListNode* node = head;
        while (node) {
            node->val = (node->val * 2) % 10;

            switch (node->next && node->next->val > 4) {
                case true:
                    node->val++;
                    break;
            }
            node = node->next;
        }
        return head;
    }
};
