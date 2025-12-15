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

        // Calculate the maximum gain for the left and right subtrees
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);

        // Update the maximum path sum found so far
        maxSum = max(maxSum, node->val + leftGain + rightGain);

        // Return the maximum gain for the current node
        return node->val + max(leftGain, rightGain);
    }
};