#include <vector>

using namespace std;

class BinaryTree {
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value);

    void insert(vector<int> values, int i = 0);

    void invertedInsert(vector<int> values, int i = 0);
};

void invertBinaryTree(BinaryTree *tree) {
    // Time: O(n), Space: O(h)
    if (!tree)
        return;
    std::swap(tree->left, tree->right);
    invertBinaryTree(tree->left);
    invertBinaryTree(tree->right);
}
