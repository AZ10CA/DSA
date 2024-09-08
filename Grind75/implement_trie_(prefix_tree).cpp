struct Node {
    char letter;
    bool is_terminating = false;
    unordered_map<char, Node*> children;

    bool hasChild(char ch) const {
        return children.find(ch) != children.end();
    }

    Node* get(char ch){
        return this->children[ch];
    }

    void insert(char ch){
        children[ch] = new Node(ch);
    }

    explicit Node(char letter): letter(letter){}
};

class Trie {
    Node* root = new Node('$');
public:
    Trie() {
        root->is_terminating = true;
    }

    void insert(string word) {
        auto ptr = root;
        for(auto letter: word){
            if(!ptr->hasChild(letter))
                ptr->insert(letter);

            ptr = ptr->get(letter);
        }

        ptr->is_terminating = true;
    }

    bool search(string word) {
        auto ptr = root;
        for(auto letter: word){
            if(!ptr->hasChild(letter))
                return false;
            ptr = ptr->get(letter);
        }

        return ptr->is_terminating;
    }

    bool startsWith(string prefix) {
        auto ptr = root;
        for(auto letter: prefix){
            if(!ptr->hasChild(letter))
                return false;
            ptr = ptr->get(letter);
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