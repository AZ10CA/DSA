struct Node {
    char letter;
    bool is_terminating = false;
    array<Node*, 26> children{};

    Node(char letter): letter(letter){}

    bool has_letter(char ch){
        return children[ch - 'a'] != nullptr;
    }

    void add_letter(char ch){
        auto new_node = new Node(ch);
        children[ch - 'a'] = new_node;
    }

    Node* get(char ch){
        return children[ch - 'a'];
    }
};

class WordDictionary {
    Node* root = new Node('$');

public:
    WordDictionary() {

    }

    void addWord(string word) {
        auto ptr = root;
        for(auto ch: word){
            if(!ptr->has_letter(ch))
                ptr->add_letter(ch);

            ptr = ptr->get(ch);
        }

        ptr->is_terminating = true;
    }

    bool search(string word) {
        return search_from(root, word, 0);
    }

    bool search_from(Node* ptr, string word, int idx){
        for(int i = idx; i < word.size(); i++){
            auto letter = word[i];
            if(letter == '.'){
                bool result = false;
                for(auto child: ptr->children)
                    if(child && !result)
                        result |= search_from(child, word, i + 1);
                return result;
            }

            if(ptr->has_letter(letter))
                ptr = ptr->get(letter);
            else
                return false;
        }

        return ptr->is_terminating;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */