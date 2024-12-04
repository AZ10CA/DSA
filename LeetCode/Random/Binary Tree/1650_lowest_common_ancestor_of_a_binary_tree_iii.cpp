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
    Node* lowestCommonAncestor(Node* p, Node * q) {
        vector<Node*> p_to_root, q_to_root;
        p_to_root.push_back(p);
        q_to_root.push_back(q);

        auto ptr = p;
        while(ptr->parent){
            p_to_root.push_back(ptr->parent);
            ptr = ptr->parent;
        }

        ptr = q;
        while(ptr->parent){
            q_to_root.push_back(ptr->parent);
            ptr = ptr->parent;
        }

        unordered_set<Node*> p_path(p_to_root.begin(), p_to_root.end());
        for(auto node: q_to_root)
            if(p_path.find(node) != p_path.end())
                return node;


        return nullptr;
    }
};