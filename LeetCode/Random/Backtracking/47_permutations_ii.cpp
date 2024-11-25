class Solution {
    unordered_set<int> used;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        set<vector<int>> result;
        vector<int> current;

        generate(current, result, nums);

        return vector<vector<int>>(result.begin(), result.end());
    }

    void generate(vector<int>& current, set<vector<int>>& result, const vector<int>& nums){
        // Time: O(n!), Space: O(n)
        if(current.size() == nums.size()){
            result.insert(current);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(used.find(i) != used.end() || (i && nums[i] == nums[i - 1] && used.find(i - 1) == used.end()))
                continue;

            used.insert(i);
            current.push_back(nums[i]);

            generate(current, result, nums);

            used.erase(i);
            current.pop_back();
        }
    }
};