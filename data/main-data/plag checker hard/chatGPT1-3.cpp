#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int globalMax = INT_MIN;  // Track the maximum path sum globally
        maxGain(root, globalMax);
        return globalMax;
    }
    
private:
    // Recursive function to compute the maximum gain from a subtree rooted at 'node'
    int maxGain(TreeNode* node, int& globalMax) {
        if (node == nullptr) {
            return 0;
        }
        
        // Recursively compute the maximum path sum from the left and right subtrees
        int leftGain = max(maxGain(node->left, globalMax), 0);  // Ignore paths with negative sums
        int rightGain = max(maxGain(node->right, globalMax), 0);
        
        // Compute the price of the current path (sum through the node and both subtrees)
        int currentPathSum = node->val + leftGain + rightGain;
        
        // Update the global maximum path sum
        globalMax = max(globalMax, currentPathSum);
        
        // Return the maximum gain that can be obtained by using the current node
        return node->val + max(leftGain, rightGain);
    }
};

int main() {
    // Example tree: 
    //      -10
    //      /  \
    //     9   20
    //        /  \
    //       15   7
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));
    
    Solution solution;
    cout << "Maximum Path Sum: " << solution.maxPathSum(root) << endl;
    
    return 0;
}
