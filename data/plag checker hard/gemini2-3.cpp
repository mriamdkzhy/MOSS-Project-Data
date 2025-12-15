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

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        helper(root, maxSum);
        return maxSum;
    }

private:
    int helper(TreeNode* root, int& maxSum) {
        if (!root) {
            return 0;
        }

        int leftMax = max(0, helper(root->left, maxSum));
        int rightMax = max(0, helper(root->right, maxSum));

        // Calculate the maximum path sum including the current node
        int currentMax = root->val + leftMax + rightMax;
        maxSum = max(maxSum, currentMax);

        // Return the maximum path sum for the subtree rooted at the current node
        return max(leftMax, rightMax) + root->val;
    }
};

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution solution;
    int maxPath = solution.maxPathSum(root);
    cout << "Maximum path sum: " << maxPath << endl;

    return 0;
}