class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return hash_set_solution(nums);
    }

    bool bruteforce_solution(const vector<int>& nums){
        // Time: O(n^2), Space: O(1) -> TLE
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] == nums[j])
                    return true;
            }
        }

        return false;
    }

    bool hash_set_solution(const vector<int>& nums){
        // Time: O(n), Space: O(n)
        unordered_set<int> nums_set(nums.begin(), nums.end());
        return nums_set.size() != nums.size();
    }
};