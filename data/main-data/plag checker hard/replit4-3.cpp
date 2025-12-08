#include <iostream>
#include <climits>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int maxSum = INT_MIN;

pair<int, int> maxPathSumUtil(Node *root) {
    if (root == nullptr) {
        return {0, 0};
    }

    pair<int, int> left = maxPathSumUtil(root->left);
    pair<int, int> right = maxPathSumUtil(root->right);

    int maxEndingHere = max({root->data, root->data + left.first, root->data + right.first});
    int maxPassingHere = max({left.second, right.second, root->data + left.first + right.first});

    maxSum = max(maxSum, maxPassingHere);

    return {maxEndingHere, maxPassingHere};
}

int maxPathSum(Node *root) {
    maxPathSumUtil(root);
    return maxSum;
}

int main() {
    Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(25);

    cout << "Maximum path sum: " << maxPathSum(root) << endl;

    return 0;
}