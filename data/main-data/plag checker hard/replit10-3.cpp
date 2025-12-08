#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxPathSum(TreeNode* root) {
  int maxSum = INT_MIN;
  
  // Recursive helper function to find the maximum path sum
  function<int(TreeNode*)> dfs = [&](TreeNode* node) {
    if (!node) {
      return 0;
    }
    
    // Calculate the maximum path sum from the left and right subtrees
    int leftSum = max(0, dfs(node->left));
    int rightSum = max(0, dfs(node->right));
    
    // Update the maximum path sum
    maxSum = max(maxSum, leftSum + rightSum + node->val);
    
    // Return the maximum path sum ending at the current node
    return max(leftSum, rightSum) + node->val;
  };
  
  dfs(root);
  return maxSum;
}

int main() {
  // Example usage
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  
  int result = maxPathSum(root);
  cout << "Maximum path sum: " << result << endl; // Output: Maximum path sum: 28
  
  return 0;
}