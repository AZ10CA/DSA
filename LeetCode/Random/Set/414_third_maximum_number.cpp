class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // Time: O(n), Space: O(1)
        set<int, std::greater<int>> max_nums;

        for(auto num: nums){
            if(max_nums.find(num) != max_nums.end())
                continue;

            max_nums.insert(num);
            if(max_nums.size() > 3)
                max_nums.erase(*max_nums.rbegin());
        }

        if(max_nums.size() < 3)
            return *max_nums.begin();

        return *max_nums.rbegin();
    }
};