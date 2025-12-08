class Solution {
    public:
        Node* doubleIt(Node* node) {
            if (node->val > 4)
                node = new ListNode(0, node);
                for(Node* n = node; n; n = n->next) {
                    n->val = (n->val * 2) % 10;
                    if (n->next && n->next->val > 4)
                        n->val++;
                }
            return node;
        }
};