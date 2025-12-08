#include <iostream>
#include <algorithm>

// Definition for a binary tree node.
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
        int maxSum = INT_MIN;
        maxPathDown(root, maxSum);
        return maxSum;
    }
    
private:
    int maxPathDown(TreeNode* node, int &maxSum) {
        if (node == nullptr) return 0;
        
        int leftMax = std::max(0, maxPathDown(node->left, maxSum));
        int rightMax = std::max(0, maxPathDown(node->right, maxSum));
        
        // Update maxSum with the maximum path sum that passes through the current node
        maxSum = std::max(maxSum, leftMax + rightMax + node->val);
        
        // Return the maximum path sum going down from the current node
        return std::max(leftMax, rightMax) + node->val;
    }
};