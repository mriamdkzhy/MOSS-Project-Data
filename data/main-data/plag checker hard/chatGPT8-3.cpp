#include <iostream>
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
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxGain(root, maxSum);
        return maxSum;
    }

private:
    int maxGain(TreeNode* node, int &maxSum) {
        if (node == nullptr) return 0;

        // Recursively get the maximum gain from the left and right subtrees
        int leftGain = std::max(maxGain(node->left, maxSum), 0);
        int rightGain = std::max(maxGain(node->right, maxSum), 0);

        // Calculate the price of the current path
        int currentPathSum = node->val + leftGain + rightGain;

        // Update maxSum if currentPathSum is greater
        maxSum = std::max(maxSum, currentPathSum);

        // Return the maximum gain the current node contributes to the path
        return node->val + std::max(leftGain, rightGain);
    }
};

// Example usage:
// int main() {
//     TreeNode *root = new TreeNode(-10);
//     root->left = new TreeNode(9);
//     root->right = new TreeNode(20);
//     root->right->left = new TreeNode(15);
//     root->right->right = new TreeNode(7);

//     Solution sol;
//     std::cout << "Maximum Path Sum: " << sol.maxPathSum(root) << std::endl;

//     return 0;
// }