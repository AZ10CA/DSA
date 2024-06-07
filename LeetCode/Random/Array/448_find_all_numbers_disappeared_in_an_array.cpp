class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // Time: O(n), Space: O(n)
        vector<bool> seen(nums.size(), false);
        for(auto num: nums)
            seen[num - 1] = true;

        vector<int> result;
        for(int i = 0; i < seen.size(); i++)
            if(!seen[i])
                result.push_back(i + 1);


        return result;
    }
};