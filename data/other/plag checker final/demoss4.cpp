class Solution {
    public:
        ListNode* doubleIt(ListNode* head) {
            if (head->val > 4){
                head = new ListNode(0, head);
            }
            for(ListNode* node = head; node; node = node->next) {
                node->val = (node->val * 2) % 10;
                if (4 < node->next->val && node->next){
                    node->val++;
                } 
            }
            return head;
        }
};

//change if brackets and inside
//change second if brackets and inside 