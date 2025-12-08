/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        /**
         * Returns the maximum path sum of any non-empty path in the binary tree.
         *
         * Args:
         *     root: The root of the binary tree.
         *
         * Returns:
         *     The maximum path sum.
         */
        int max_sum = INT_MIN;  // Initialize max_sum to negative infinity

        maxGain(root, max_sum);  // Calculate max_sum
        return max_sum;
    }

private:
    int maxGain(TreeNode* node, int& max_sum) {
        /**
         * Recursive helper function to calculate the maximum gain of a node.
         *
         * Returns the maximum gain of the current node.
         */
        if (!node) {
            return 0;
        }

        // Recursively calculate the maximum gain of the left and right subtrees
        int left_gain = max(maxGain(node->left, max_sum), 0);
        int right_gain = max(maxGain(node->right, max_sum), 0);

        // Update max_sum if the current path sum is greater
        max_sum = max(max_sum, node->val + left_gain + right_gain);

        // Return the maximum gain of the current node
        return node->val + max(left_gain, right_gain);
    }
};