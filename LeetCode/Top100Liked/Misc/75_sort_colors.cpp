class Solution {
public:
    void sortColors(vector<int> &nums) {
        // Time: O(n), Space: O(1)
        vector<int> frequency(3, 0);
        for (auto num: nums)
            frequency[num]++;

        int idx = 0;
        for (int i = 0; i < frequency.size(); i++)
            for (int j = 0; j < frequency[i]; j++)
                nums[idx++] = i;
    }
};