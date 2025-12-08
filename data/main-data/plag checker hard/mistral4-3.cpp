#include <iostream>
#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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

        // Update the global maximum path sum
        maxSum = std::max(maxSum, node->val + leftMax + rightMax);

        // Return the maximum path sum that includes the current node
        return node->val + std::max(leftMax, rightMax);
    }
};

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution solution;
    std::cout << "Maximum Path Sum: " << solution.maxPathSum(root) << std::endl;

    // Clean up the allocated memory
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
