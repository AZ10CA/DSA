#include <vector>

using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

void getSums(BinaryTree *node, vector<int> &sums, int sum) {
    if (!node)
        return;

    if (!node->left && !node->right)
        sums.push_back(sum + node->value);
    else {
        getSums(node->left, sums, sum + node->value);
        getSums(node->right, sums, sum + node->value);
    }
}

vector<int> branchSums(BinaryTree *root) {
    // Time: O(n), Space: O(n)
    vector<int> sums;
    getSums(root, sums, 0);
    return sums;
}
