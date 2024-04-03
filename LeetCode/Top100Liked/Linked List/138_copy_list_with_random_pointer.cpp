/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Time: O(n), Space: O(n)
        if(!head)
            return nullptr;

        // make a copy of the list
        auto cpy = new Node(0);
        auto head_copy = cpy;
        auto iter = head;
        while(iter){
            cpy->next = new Node(iter->val);
            cpy = cpy->next;
            iter = iter->next;
        }

        head_copy = head_copy->next; // head of the copied list

        unordered_map<Node*, Node*> address_to_address; // maps the node addressed in the original list to the copied list nodes
        iter = head;
        auto cpy_iter = head_copy;
        while(iter){
            address_to_address[iter] = cpy_iter;
            cpy_iter = cpy_iter->next;
            iter = iter->next;
        }

        // connect the random pointers
        iter = head;
        cpy_iter = head_copy;
        while(iter){
            if(iter->random){
                auto from = iter;
                auto to = iter->random;
                auto cpy_from = address_to_address[from];
                auto cpy_to = address_to_address[to];
                cpy_from->random = cpy_to;
            }
            iter = iter->next;
            cpy_iter = cpy_iter->next;
        }

        return head_copy;
    }
};