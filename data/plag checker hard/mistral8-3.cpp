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

        // Calculate the maximum path sum of the left and right subtrees
        int leftMax = max(maxPathSumHelper(node->left, maxSum), 0);
        int rightMax = max(maxPathSumHelper(node->right, maxSum), 0);

        // Update the maximum path sum considering the current node
        int currentMax = node->val + leftMax + rightMax;
        maxSum = max(maxSum, currentMax);

        // Return the maximum path sum that can be obtained with this node as the highest node
        return node->val + max(leftMax, rightMax);
    }
};

// Helper function to create a new tree node
TreeNode* newNode(int val) {
    TreeNode* node = new TreeNode(val);
    node->left = node->right = NULL;
    return node;
}

// Example usage
int main() {
    // Create a sample binary tree
    /*
            1
           / \
          2   3
    */
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    Solution solution;
    cout << "Maximum Path Sum: " << solution.maxPathSum(root) << endl;

    return 0;
}
