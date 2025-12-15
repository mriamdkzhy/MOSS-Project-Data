#include <iostream>
#include <algorithm>
#include <limits> // Required for numeric_limits

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxPathSumHelper(TreeNode* root, int& maxSum) {
    // Base case: empty subtree
    if (root == nullptr) {
        return 0;
    }

    // Recursively calculate max path sum from left and right subtrees
    int leftMax = maxPathSumHelper(root->left, maxSum);
    int rightMax = maxPathSumHelper(root->right, maxSum);

    // Calculate the maximum path sum going through the current node
    int maxPathThroughNode = max({root->val, root->val + leftMax, root->val + rightMax, root->val + leftMax + rightMax});

    // Update the global maximum sum
    maxSum = max(maxSum, maxPathThroughNode);

    // Return the maximum path sum starting from the current node (for parent node calculations)
    return max({root->val, root->val + leftMax, root->val + rightMax});

}

int maxPathSum(TreeNode* root) {
    int maxSum = numeric_limits<int>::min(); // Initialize with the smallest possible integer
    maxPathSumHelper(root, maxSum);
    return maxSum;
}


int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(-10);

    int result = maxPathSum(root);
    cout << "Maximum path sum: " << result << endl; // Output: 6

    //Clean up memory (important to avoid leaks)
    //Add a function to delete the tree to avoid memory leaks.  This is left as an exercise.

    return 0;
}