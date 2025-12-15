#include <algorithm>
#include <climits>

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
        maxPathSumHelper(root, maxSum);
        return maxSum;
    }

private:
    int maxPathSumHelper(TreeNode* node, int& maxSum) {
        if (!node) return 0;

        // Compute the maximum path sum of the left and right subtrees
        int leftMax = std::max(maxPathSumHelper(node->left, maxSum), 0);
        int rightMax = std::max(maxPathSumHelper(node->right, maxSum), 0);

        // Update the overall maximum path sum
        maxSum = std::max(maxSum, node->val + leftMax + rightMax);

        // Return the maximum path sum that includes the current node and at most one of its subtrees
        return node->val + std::max(leftMax, rightMax);
    }
};
