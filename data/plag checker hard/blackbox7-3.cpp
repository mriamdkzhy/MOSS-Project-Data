class Solution {
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        maxGain(root);
        return maxSum;
    }

private:
    int maxSum;
    int maxGain(TreeNode* node) {
        if (!node) return 0;
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);
        maxSum = max(maxSum, node->val + leftGain + rightGain);
        return node->val + max(leftGain, rightGain);
    }
};