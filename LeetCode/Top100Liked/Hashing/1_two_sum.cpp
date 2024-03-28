class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Time & Space: O(n)
        unordered_map<int, int> required;
        vector<int> result;

        for(int i = 0; i < nums.size(); i++){
            auto num = nums[i];
            if(required.find(num) != required.end()){
                result.push_back(required[num]);
                result.push_back(i);
            } else {
                required[target - num] = i;
            }
        }

        return result;
    }
};