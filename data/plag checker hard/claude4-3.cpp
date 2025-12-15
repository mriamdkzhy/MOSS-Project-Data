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
        int maxSum = INT_MIN;
        maxPathSumUtil(root, maxSum);
        return maxSum;
    }
    
private:
    int maxPathSumUtil(TreeNode* node, int& maxSum) {
        if (node == nullptr) {
            return 0;
        }
        
        // Recursively compute the maximum path sum for left and right subtrees
        int leftSum = max(0, maxPathSumUtil(node->left, maxSum));
        int rightSum = max(0, maxPathSumUtil(node->right, maxSum));
        
        // Update the maximum path sum
        maxSum = max(maxSum, node->val + leftSum + rightSum);
        
        // Return the maximum sum for a path ending at the current node
        return node->val + max(leftSum, rightSum);
    }
};