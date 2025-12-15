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
        maxPathSumHelper(root, maxSum);
        return maxSum;
    }
    
private:
    int maxPathSumHelper(TreeNode* node, int& maxSum) {
        if (node == nullptr) {
            return 0;
        }
        
        // Recursively compute the maximum path sum for left and right subtrees
        int leftSum = max(0, maxPathSumHelper(node->left, maxSum));
        int rightSum = max(0, maxPathSumHelper(node->right, maxSum));
        
        // Compute the maximum path sum through the current node
        int currentPathSum = node->val + leftSum + rightSum;
        
        // Update the global maximum if necessary
        maxSum = max(maxSum, currentPathSum);
        
        // Return the maximum sum of a path from this node to one of its children
        return node->val + max(leftSum, rightSum);
    }
};