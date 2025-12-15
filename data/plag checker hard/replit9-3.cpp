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
  if (root == NULL) {
    return 0;
  }

  int maxSum = numeric_limits<int>::min();
  maxPathSumHelper(root, maxSum);
  return maxSum;
}

int maxPathSumHelper(TreeNode* node, int& maxSum) {
  if (node == NULL) {
    return 0;
  }

  int leftSum = maxPathSumHelper(node->left, maxSum);
  int rightSum = maxPathSumHelper(node->right, maxSum);

  int currentMax = max(max(leftSum, rightSum) + node->val, node->val);
  maxSum = max(maxSum, max(currentMax, leftSum + rightSum + node->val));

  return currentMax;
}

int main() {
  // Construct a binary tree
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  int maxPath = maxPathSum(root);
  cout << "Maximum path sum: " << maxPath << endl;

  return 0;
}