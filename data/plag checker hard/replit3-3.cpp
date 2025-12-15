#include <iostream>
#include <climits>

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

    int maxSum = INT_MIN;
    maxPathSumHelper(root, maxSum);

    return maxSum;
}

int maxPathSumHelper(TreeNode* node, int& maxSum) {
    if (node == nullptr) {
        return 0;
    }

    int leftSum = maxPathSumHelper(node->left, maxSum);
    int rightSum = maxPathSumHelper(node->right, maxSum);

    int currentMax = max(node->val, max(node->val + leftSum, node->val + rightSum));

    maxSum = max(maxSum, max(currentMax, node->val + leftSum + rightSum));

    return currentMax;
}

int main() {
    // Example tree:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int maxPath = maxPathSum(root);
    cout << "Maximum Path Sum: " << maxPath << endl;

    return 0;
}