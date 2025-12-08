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
        
        // Max sum on the left and right sub-trees of node
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);
        
        // Price to start a new path where `node` is the highest node
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

// Example usage
int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    Solution solution;
    cout << "Maximum Path Sum: " << solution.maxPathSum(root) << endl;
    
    // Don't forget to free the allocated memory in a real application
    return 0;
}