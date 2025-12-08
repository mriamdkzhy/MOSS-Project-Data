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
        if (!node) return 0;

        // Compute the maximum path sum of the left and right subtrees
        int leftMax = max(maxPathSumHelper(node->left, maxSum), 0);
        int rightMax = max(maxPathSumHelper(node->right, maxSum), 0);

        // Current path sum passing through this node
        int currentPathSum = node->val + leftMax + rightMax;

        // Update the global maximum path sum
        maxSum = max(maxSum, currentPathSum);

        // Return the maximum path sum that can be obtained by extending through one child
        return node->val + max(leftMax, rightMax);
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution solution;
    int result = solution.maxPathSum(root);
    cout << "Maximum Path Sum: " << result << endl;

    return 0;
}
