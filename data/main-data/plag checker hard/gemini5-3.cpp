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
    // Base case: Empty subtree
    if (root == nullptr) {
        return 0;
    }

    // Recursively calculate the maximum path sum from the left and right subtrees.
    int leftSum = maxPathSumHelper(root->left, maxSum);
    int rightSum = maxPathSumHelper(root->right, maxSum);

    // Consider paths that go through the current node.
    int maxPathThroughNode = max({root->val, root->val + leftSum, root->val + rightSum, root->val + leftSum + rightSum});

    // Update the global maximum sum.
    maxSum = max(maxSum, maxPathThroughNode);

    // Return the maximum path sum that starts at the current node and goes down only one side.  This is crucial for correctly building up paths.
    return max({root->val, root->val + leftSum, root->val + rightSum});

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
    // Add a function to delete the tree to avoid memory leaks.  This is a simple post-order traversal.
    function<void(TreeNode*)> deleteTree = [&](TreeNode* node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    };
    deleteTree(root);

    return 0;
}