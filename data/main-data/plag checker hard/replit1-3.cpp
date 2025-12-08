#include <iostream>
#include <limits>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxPathSum(TreeNode* root) {
  int maxSum = numeric_limits<int>::min();
  maxPathSumHelper(root, maxSum);
  return maxSum;
}

int maxPathSumHelper(TreeNode* root, int& maxSum) {
  if (root == NULL) {
    return 0;
  }

  int leftSum = maxPathSumHelper(root->left, maxSum);
  int rightSum = maxPathSumHelper(root->right, maxSum);

  // Calculate the maximum path sum that includes the current node
  int currentPathSum = max(max(leftSum, rightSum) + root->val, root->val);

  // Calculate the maximum path sum that passes through the current node
  int maxPathThroughNode = max(currentPathSum, leftSum + rightSum + root->val);

  // Update the global maximum sum
  maxSum = max(maxSum, maxPathThroughNode);

  return currentPathSum;
}

int main() {
  // Create a sample binary tree
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  // Find the maximum path sum
  int maxPathSumValue = maxPathSum(root);

  // Print the result
  cout << "Maximum Path Sum: " << maxPathSumValue << endl;

  return 0;
}