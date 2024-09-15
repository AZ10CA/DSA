class LRUCache {
    std::list<pair<int, int>> li;
    unordered_map<int, std::list<pair<int, int>>::iterator> map;

    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if(map.find(key) == map.end())
            return -1;

        set_as_used(key);

        return map[key]->second;
    }

    void put(int key, int value) {
        if(map.find(key) != map.end()){
            set_as_used(key);
            map[key]->second = value;
        } else {
            if(li.size() == capacity){
                map.erase(li.begin()->first);
                li.erase(li.begin());
            }

            li.insert(li.end(), make_pair(key, value));
            map[key] = std::prev(li.end());
        }
    }

    void set_as_used(int key){
        std::list<pair<int, int>>::iterator address = map[key];
        pair<int, int> node = *address;

        li.erase(address);
        li.insert(li.end(), node);

        map[key] = std::prev(li.end());
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */