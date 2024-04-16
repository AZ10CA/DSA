class Trie {
    struct Node {
        vector<Node*> children;
        bool is_ending = false;

        Node():children(26, nullptr){}

        bool has_child(char ch){
            return children[ch - 'a'] != nullptr;
        }

        Node* get_child(char ch){
            return children[ch - 'a'];
        }

        void insert(char ch){
            children[ch - 'a'] = new Node();
        }
    };

    Node* head;
public:
    Trie() {
        head = new Node();
    }

    void insert(string word) {
        // Time: O(n), Space: O(n), n: size of the word
        auto ptr = head;
        for(auto ch: word){
            if(not ptr->has_child(ch))
                ptr->insert(ch);
            ptr = ptr->get_child(ch);
        }
        ptr->is_ending = true;
    }

    bool search(string word) {
        // Time: O(n), Space: O(1), n: size of word
        auto ptr = head;
        for(auto ch: word){
            if(ptr->has_child(ch))
                ptr = ptr->get_child(ch);
            else
                return false;
        }

        return ptr->is_ending;
    }

    bool startsWith(string prefix) {
        // Time: O(p), Space: O(1), p: size of prefix
        auto ptr = head;
        for(auto ch: prefix){
            if(ptr->has_child(ch))
                ptr = ptr->get_child(ch);
            else
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */