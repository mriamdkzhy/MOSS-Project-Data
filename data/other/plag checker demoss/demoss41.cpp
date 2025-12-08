class Solution {
    public:
        ListNode* doubleIt(ListNode* head) {
            if (4 < head->val)
                head = new ListNode(0, head);
                {ListNode* node = head;
while(node){
	{
                    node->val = (node->val * 2) % 10;
                    if (node->next && 4 < node->next->val)
                        node->val += 1;
                }
	node = node->next;
}}
            return head;
        }
};