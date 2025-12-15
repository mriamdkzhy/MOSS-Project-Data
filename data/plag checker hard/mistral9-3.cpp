#include <iostream>
#include <algorithm>
using namespace std;

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
        maxPathSumHelper(root, maxSum);
        return maxSum;
    }

private:
    int maxPathSumHelper(TreeNode* node, int& maxSum) {
        if (node == nullptr) {
            return 0;
        }

        // Compute the maximum path sum of the left and right subtrees
        int leftMax = max(maxPathSumHelper(node->left, maxSum), 0);
        int rightMax = max(maxPathSumHelper(node->right, maxSum), 0);

        // Current path sum through the node
        int currentPathSum = node->val + leftMax + rightMax;

        // Update the global maximum path sum
        maxSum = max(maxSum, currentPathSum);

        // Return the maximum path sum that includes the current node
        return node->val + max(leftMax, rightMax);
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution solution;
    int result = solution.maxPathSum(root);
    cout << "Maximum Path Sum: " << result << endl;

    return 0;
}
