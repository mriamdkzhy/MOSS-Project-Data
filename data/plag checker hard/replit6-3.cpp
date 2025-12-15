#include <iostream>
#include <limits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN; // Initialize the maximum sum to the smallest possible integer
    
    function<int(TreeNode*)> helper = [&](TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        
        int leftSum = max(0, helper(node->left)); // Calculate the maximum sum from the left subtree
        int rightSum = max(0, helper(node->right)); // Calculate the maximum sum from the right subtree
        
        int currentSum = leftSum + rightSum + node->val; // Calculate the current path sum
        maxSum = max(maxSum, currentSum); // Update the maximum sum if necessary
        
        return max(leftSum, rightSum) + node->val; // Return the maximum sum from the left or right subtree plus the current node's value
    };
    
    helper(root); // Call the helper function to traverse the tree
    return maxSum; // Return the maximum path sum
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    int maxPath = maxPathSum(root);
    cout << "Maximum Path Sum: " << maxPath << endl;
    
    return 0;
}