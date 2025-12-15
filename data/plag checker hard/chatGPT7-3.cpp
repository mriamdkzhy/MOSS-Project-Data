#include <iostream>
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
        maxGain(root, maxSum);
        return maxSum;
    }
    
private:
    int maxGain(TreeNode* node, int &maxSum) {
        if (!node) return 0;

        // Recursively get the maximum gain from left and right subtrees
        int leftGain = std::max(maxGain(node->left, maxSum), 0);
        int rightGain = std::max(maxGain(node->right, maxSum), 0);

        // Current path sum including the current node
        int currentPathSum = node->val + leftGain + rightGain;
        
        // Update the maximum path sum found so far
        maxSum = std::max(maxSum, currentPathSum);

        // Return the maximum gain the parent node can get from this node
        return node->val + std::max(leftGain, rightGain);
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    int result = sol.maxPathSum(root);
    std::cout << "Maximum Path Sum: " << result << std::endl; // Output should be 42

    // Clean up memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}