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

int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    
    // Helper function to calculate the maximum path sum starting from a given node
    function<int(TreeNode*)> maxPathSumFromNode = [&](TreeNode* node) {
        if (!node) {
            return 0;
        }
        
        int leftSum = max(0, maxPathSumFromNode(node->left));
        int rightSum = max(0, maxPathSumFromNode(node->right));
        
        // Calculate the maximum path sum passing through the current node
        int currentMax = node->val + leftSum + rightSum;
        
        // Update the global maximum sum
        maxSum = max(maxSum, currentMax);
        
        // Return the maximum path sum starting from the current node, including only one branch (left or right)
        return node->val + max(leftSum, rightSum);
    };
    
    maxPathSumFromNode(root);
    
    return maxSum;
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    int maxPathSumValue = maxPathSum(root);
    cout << "Maximum path sum: " << maxPathSumValue << endl;
    
    return 0;
}