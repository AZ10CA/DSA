class BST {
public:
    int value;
    BST *left;
    BST *right;

    BST(int val);

    BST &insert(int val);
};

bool is_valid(BST *node, int min, int max);

bool validateBst(BST *tree) {
    return is_valid(tree, INT_MIN, INT_MAX);
}

bool is_valid(BST *node, int min, int max) {
    // Time: O(n), Space: O(h)
    if (not node)
        return true;

    bool is_value_valid = node->value >= min && node->value < max;
    bool is_left_subtree_valid = is_valid(node->left, min, node->value);
    bool is_right_subtree_valid = is_valid(node->right, node->value, max);

    return is_value_valid && is_left_subtree_valid && is_right_subtree_valid;
}
