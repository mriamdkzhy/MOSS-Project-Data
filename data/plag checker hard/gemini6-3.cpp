#include <iostream>
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
        int maxSum = INT_MIN; // Initialize with the smallest possible integer
        dfs(root, maxSum);
        return maxSum;
    }

private:
    int dfs(TreeNode* node, int& maxSum) {
        if (node == nullptr) return 0;

        int leftMax = dfs(node->left, maxSum);
        int rightMax = dfs(node->right, maxSum);

        // Update maxSum with the maximum path sum including the current node
        maxSum = std::max(maxSum, std::max(0, leftMax) + std::max(0, rightMax) + node->val);


        // Return the maximum path sum ending at the current node
        return std::max(0, std::max(leftMax, rightMax)) + node->val;
    }
};