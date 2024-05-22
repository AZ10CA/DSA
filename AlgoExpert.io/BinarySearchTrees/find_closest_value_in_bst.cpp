class BST {
public:
    int value;
    BST *left;
    BST *right;

    BST(int val);

    BST &insert(int val);
};

void find_closest(BST *node, int target, int &answer);

int findClosestValueInBst(BST *tree, int target) {
    // Time: O(n), Space: O(n)
    int answer = tree->value;
    find_closest(tree, target, answer);
    return answer;
}

void find_closest(BST *node, int target, int &answer) {
    if (!node)
        return;

    if (std::abs(node->value - target) <= std::abs(answer - target))
        answer = node->value;

    if (node->value < target)
        find_closest(node->right, target, answer);
    else
        find_closest(node->left, target, answer);
}
