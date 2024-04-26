/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> call_stack;

    void push_left_nodes(TreeNode* root){
        while(root){
            call_stack.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        push_left_nodes(root);
    }

    int next() {
        auto top = call_stack.top();
        call_stack.pop();
        if(top->right)
            push_left_nodes(top->right);

        return top->val;
    }

    bool hasNext() {
        return !call_stack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */