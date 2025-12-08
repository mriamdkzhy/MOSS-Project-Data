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
    // Base Case: If the current node is null, return 0.  This signifies no contribution to the path sum.
    if (root == nullptr) {
        return 0;
    }

    // Recursively calculate the maximum path sum from the left and right subtrees.
    int leftSum = maxPathSumHelper(root->left, maxSum);
    int rightSum = maxPathSumHelper(root->right, maxSum);

    // Calculate the maximum path sum going through the current node.  Consider three possibilities:
    // 1. Only the current node's value.
    // 2. Current node + left subtree.
    // 3. Current node + right subtree.
    // 4. Current node + left subtree + right subtree.
    int maxPathThroughNode = max({root->val, root->val + leftSum, root->val + rightSum, root->val + leftSum + rightSum});

    // Update the global maximum sum if a larger sum is found.
    maxSum = max(maxSum, maxPathThroughNode);


    // Return the maximum path sum that can be extended from the current node upwards. This excludes paths that end at the current node.
    return max(0, max(leftSum, rightSum) + root->val); //Return the max of 0 and the sum including the current node. 0 handles negative paths that should be excluded.

}

int maxPathSum(TreeNode* root) {
    int maxSum = numeric_limits<int>::min(); // Initialize with the smallest possible integer.
    maxPathSumHelper(root, maxSum);
    return maxSum;
}


int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(-1);

    int result = maxPathSum(root);
    cout << "Maximum path sum: " << result << endl; // Output: 6

    //Clean up memory (important to avoid leaks!)
    //Implement a function to delete the tree to avoid memory leaks.  This is omitted for brevity but is crucial in production code.

    return 0;
}