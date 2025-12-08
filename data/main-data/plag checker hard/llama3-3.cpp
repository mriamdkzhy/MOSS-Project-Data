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
public:
    int maxPathSum(TreeNode* root) {
        // Initialize max_sum as negative infinity
        int max_sum = INT_MIN;
        
        // Call maxGain to calculate max_path_sum and update max_sum
        maxGain(root, max_sum);
        
        // Return max_sum
        return max_sum;
    }
    
    // Helper function to calculate max_gain and update max_sum
    int maxGain(TreeNode* node, int& max_sum) {
        // Base case: If node is nullptr, return 0
        if (!node) return 0;
        
        // Recursively calculate max_gain for left and right subtrees
        int left_gain = max(maxGain(node->left, max_sum), 0);
        int right_gain = max(maxGain(node->right, max_sum), 0);
        
        // Update max_sum if current path sum is greater
        max_sum = max(max_sum, node->val + left_gain + right_gain);
        
        // Return max_gain for current node
        return node->val + max(left_gain, right_gain);
    }
};