/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int maxSum;
    
    int maxGain(TreeNode* node) {
        if (!node) return 0;
        
        // Recursively compute max gain from left and right subtrees
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);
        
        // Price to start a new path where `node` is the highest point
        int priceNewPath = node->val + leftGain + rightGain;
        
        // Update maxSum if it's better to start a new path
        maxSum = max(maxSum, priceNewPath);
        
        // For recursion: return the max gain if continue the same path
        return node->val + max(leftGain, rightGain);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        maxGain(root);
        return maxSum;
    }
};