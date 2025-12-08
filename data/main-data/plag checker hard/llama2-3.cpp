/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        max_sum = INT_MIN;
        dfs(root);
        return max_sum;
    }
    
private:
    int max_sum;
    
    // Returns the maximum path sum of the subtree rooted at node.
    int dfs(TreeNode* node) {
        if (!node) return 0;
        
        // Calculate the maximum path sum for the left and right subtrees.
        int left_sum = max(dfs(node->left), 0);
        int right_sum = max(dfs(node->right), 0);
        
        // Update the maximum path sum if the current path has a larger sum.
        max_sum = max(max_sum, node->val + left_sum + right_sum);
        
        // Return the maximum path sum for the current node.
        return node->val + max(left_sum, right_sum);
    }
};