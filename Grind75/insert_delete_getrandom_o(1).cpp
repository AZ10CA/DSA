class RandomizedSet {
    unordered_map<int, int> num_to_idx;
    vector<int> nums;
public:
    RandomizedSet() {
        [=](){
            ios_base::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
        }();
    }

    bool insert(int val) {
        if(num_to_idx.find(val) != num_to_idx.end())
            return false;

        num_to_idx[val] = nums.size();
        nums.push_back(val);

        return true;
    }

    bool remove(int val) {
        if(num_to_idx.find(val) == num_to_idx.end() || nums.empty())
            return false;

        auto idx = num_to_idx[val];
        int last_idx = nums.size() - 1;

        int last_num = nums[last_idx];
        std::swap(nums[idx], nums[last_idx]);

        num_to_idx[last_num] = idx;
        nums.pop_back();
        num_to_idx.erase(val);

        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */