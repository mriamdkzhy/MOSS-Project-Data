/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        dfs(root, max_sum);
        return max_sum;
    }

private:
    int dfs(TreeNode* node, int& max_sum) {
        if (!node) return 0;

        // Calculate the maximum path sum for the left and right subtrees
        int left_sum = max(dfs(node->left, max_sum), 0);
        int right_sum = max(dfs(node->right, max_sum), 0);

        // Update the maximum path sum if the current path has a larger sum
        max_sum = max(max_sum, node->val + left_sum + right_sum);

        // Return the maximum path sum for the current node
        return node->val + max(left_sum, right_sum);
    }
};