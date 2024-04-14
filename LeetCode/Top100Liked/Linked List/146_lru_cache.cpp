class LRUCache {
public:
    list<pair<int, int>> items;
    unordered_map<int, list<pair<int, int>>::iterator> map;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if(map.find(key) != map.end()){
            items.splice(items.begin(), items, map[key]);
            return items.begin()->second;
        }
        return -1;
    }

    void put(int key, int value) {
        if(map.find(key) != map.end()){
            // if you find the element, update its value and move it to front
            items.splice(items.begin(), items, map[key]);
            *items.begin() = {key, value};
            map[key]->second = value;
        } else if(items.size() == capacity) {
            // capacity is reached
            map.erase(items.back().first);
            items.pop_back();
            items.push_front({key, value});
            map[key] = items.begin();
        } else {
            // key not found and capacity is not reached
            items.push_front({key, value});
            map[key] = items.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */