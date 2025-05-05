/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        // Time: O(n), Space: O(n)
        auto root = find_root(node);
        vector<Node*> inorder;
        inorder_traversal(root, inorder);

        bool found = false;
        for(auto each: inorder){
            if(found)
                return each;
            if(each == node)
                found = true;
        }

        return nullptr;
    }


    Node* find_root(Node* node){
        while(node->parent)
            node = node->parent;

        return node;
    }

    void inorder_traversal(Node* root, vector<Node*>& nodes){
        if(not root)
            return;

        inorder_traversal(root->left, nodes);
        nodes.push_back(root);
        inorder_traversal(root->right, nodes);
    }
};