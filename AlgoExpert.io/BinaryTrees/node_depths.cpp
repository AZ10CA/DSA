using namespace std;

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

void sumDepths(BinaryTree *node, int current_depth, int &sum) {
    if (!node)
        return;

    sum += current_depth;
    sumDepths(node->left, current_depth + 1, sum);
    sumDepths(node->right, current_depth + 1, sum);
}

int nodeDepths(BinaryTree *root) {
    // Time: O(n), Space: O(h)
    int sum = 0;
    sumDepths(root, 0, sum);
    return sum;
}
