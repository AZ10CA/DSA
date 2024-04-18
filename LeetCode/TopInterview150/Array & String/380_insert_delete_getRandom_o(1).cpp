class RandomizedSet {
    vector<int> elements;
    unordered_map<int, int> indices;
    RandomizedSet() {
    }

    bool insert(int val){
        if(indices.find(val) != indices.end())
            return false;
        indices[val] = elements.size();
        elements.push_back(val);
        return true;

    }

    bool remove(int val) {
        if(indices.find(val) == indices.end())
            return false;

        auto index = indices[val];
        auto last_index = elements.size() - 1;

        if(index != last_index){
            std::swap(elements[index], elements[last_index]);
            indices[elements[index]] = index;
        }

        indices.erase(val);
        elements.pop_back();

        return true;
    }

    int getRandom() {
        return elements[rand() % elements.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */