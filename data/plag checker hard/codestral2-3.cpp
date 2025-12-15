#include<bits/stdc++.h>
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
        int max_sum = INT_MIN;
        maxPathDown(root, max_sum);
        return max_sum;
    }

private:
    int maxPathDown(TreeNode* node, int &max_sum) {
        if (node == nullptr) return 0;
        int left = max(0, maxPathDown(node->left, max_sum));
        int right = max(0, maxPathDown(node->right, max_sum));
        max_sum = max(max_sum, left + right + node->val);
        return max(left, right) + node->val;
    }
};
