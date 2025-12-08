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
    if (root == nullptr) {
        return 0;
    }

    int maxSum = root->val;
    int maxLeft = maxPathSum(root->left);
    int maxRight = maxPathSum(root->right);

    // Calculate the maximum path sum for paths that include the current node
    maxSum = max(maxSum, max(maxLeft + root->val, maxRight + root->val));
    maxSum = max(maxSum, maxLeft + root->val + maxRight); 

    return maxSum;
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    int maxSum = maxPathSum(root);
    cout << "Maximum path sum: " << maxSum << endl;

    delete root;
    delete root->left;
    delete root->right;

    return 0;
}