#include <algorithm>
#include <climits>

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
private:
    int maxSum;
    
    int maxPathSumHelper(TreeNode* node) {
        if (node == nullptr) return 0;
        
        // Recursively compute the maximum path sum for left and right subtrees
        int leftSum = std::max(maxPathSumHelper(node->left), 0);
        int rightSum = std::max(maxPathSumHelper(node->right), 0);
        
        // Compute the maximum path sum through the current node
        int currentPathSum = node->val + leftSum + rightSum;
        
        // Update the global maximum sum if necessary
        maxSum = std::max(maxSum, currentPathSum);
        
        // Return the maximum sum of a path that can be extended to the parent
        return node->val + std::max(leftSum, rightSum);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        maxPathSumHelper(root);
        return maxSum;
    }
};