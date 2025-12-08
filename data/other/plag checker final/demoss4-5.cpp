class Solution {
public:
    Node* doubleIt(Node* node) {
        // Replacing 'if' with 'switch' statement
        switch (4 < node->val) {
            case true:
                node = new ListNode(0, node);
                break;
        }
        Node* n = node;
        while (n == true) {
            n->val = (n->val * 2) % 10;

            switch (4 < n->next->val && n->next) {
                case true:
                    n->val = n->val + 1;
                    break;
            }
            n = n->next;
        }
        return node;
    }
};