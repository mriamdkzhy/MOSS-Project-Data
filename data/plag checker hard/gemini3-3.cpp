#include <iostream>
#include <limits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        helper(root, maxSum);
        return maxSum;
    }

private:
    int helper(TreeNode* root, int& maxSum) {
        if (root == nullptr) {
            return 0;
        }

        int leftSum = max(0, helper(root->left, maxSum));
        int rightSum = max(0, helper(root->right, maxSum));

        int singlePathSum = root->val + leftSum + rightSum;
        maxSum = max(maxSum, singlePathSum);

        return root->val + max(leftSum, rightSum);
    }
};

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
    Solution solution;
    int maxPath = solution.maxPathSum(root);

    cout << "Maximum path sum: " << maxPath << endl;

    return 0;
}