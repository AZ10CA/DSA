using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
    int value;
    BinaryTree *left = nullptr;
    BinaryTree *right = nullptr;

    BinaryTree(int value) { this->value = value; }
};

bool is_symmetrical(BinaryTree *l_node, BinaryTree *r_node);

bool symmetricalTree(BinaryTree *tree) {
    // Time: O(n), Space: O(h)
    return is_symmetrical(tree->left, tree->right);
}

bool is_symmetrical(BinaryTree *l_node, BinaryTree *r_node) {
    if (l_node == nullptr && r_node == nullptr)
        return true;

    if (l_node == nullptr || r_node == nullptr)
        return false;

    return l_node->value == r_node->value &&
           is_symmetrical(l_node->left, r_node->right) &&
           is_symmetrical(l_node->right, r_node->left);
}
