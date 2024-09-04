class Solution {
public:
    int missingNumber(vector<int>& nums) {
        return marking_solution(nums);
    }

    int marking_solution(vector<int>& nums){
        // Time: O(n), Space: O(1)
        for(auto& num: nums)
            num++;

        nums.push_back(42);

        for(int i = 0; i < nums.size() - 1; i++){
            int idx = std::abs(nums[i]) - 1;
            nums[idx] *= -1;
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0)
                return i;
        }

        return 42;
    }

    int hash_set_solution(const vector<int>& nums){
        // Time: O(n), Space: O(n)
        unordered_set<int> set(nums.begin(), nums.end());

        for(int i = 0; i <= nums.size(); i++)
            if(set.find(i) == set.end())
                return i;

        return 42;
    }
};