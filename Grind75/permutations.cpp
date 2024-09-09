class Solution {
    unordered_set<int> used;
    vector<vector<int>> result;
    vector<int> current;

public:
    vector<vector<int>> permute(vector<int>& nums) {
        // Time: O(n!), Space: O(n!)
        generate(nums);
        return result;
    }

    void generate(const vector<int>& nums){
        if(current.size() == nums.size()){
            result.push_back(current);
            return;
        }

        for(auto& num: nums){
            if(used.find(num) != used.end())
                continue;

            used.insert(num);
            current.push_back(num);
            generate(nums);

            current.pop_back();
            used.erase(num);
        }
    }
};