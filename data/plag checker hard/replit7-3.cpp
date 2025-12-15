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
    int maxSum = INT_MIN;
    int maxPathSumHelper(TreeNode* root, int& maxSum) {
        if (root == NULL) {
            return 0;
        }

        int leftSum = maxPathSumHelper(root->left, maxSum);
        int rightSum = maxPathSumHelper(root->right, maxSum);

        int currentMax = max(root->val, max(root->val + leftSum, root->val + rightSum));
        maxSum = max(maxSum, max(currentMax, root->val + leftSum + rightSum));

        return currentMax;
    }
    maxPathSumHelper(root, maxSum);
    return maxSum;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int result = maxPathSum(root);
    cout << "Maximum path sum: " << result << endl;

    return 0;
}