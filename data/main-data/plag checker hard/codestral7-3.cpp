#include <climits>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        maxPathSumHelper(root, max_sum);
        return max_sum;
    }

private:
    int maxPathSumHelper(TreeNode* node, int& max_sum) {
        if (node == nullptr) {
            return 0;
        }

        int left_sum = std::max(maxPathSumHelper(node->left, max_sum), 0);
        int right_sum = std::max(maxPathSumHelper(node->right, max_sum), 0);

        max_sum = std::max(max_sum, node->val + left_sum + right_sum);

        return node->val + std::max(left_sum, right_sum);
    }
};
