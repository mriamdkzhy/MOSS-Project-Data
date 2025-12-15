#include <algorithm>
#include <climits>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int maxSum;
    
    int maxPathSumHelper(TreeNode* node) {
        if (node == nullptr) return 0;
        
        // Recursively compute the maximum path sum for left and right subtrees
        int leftSum = std::max(maxPathSumHelper(node->left), 0);
        int rightSum = std::max(maxPathSumHelper(node->right), 0);
        
        // Compute the maximum path sum through the current node
        int currPathSum = node->val + leftSum + rightSum;
        
        // Update the global maximum if necessary
        maxSum = std::max(maxSum, currPathSum);
        
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