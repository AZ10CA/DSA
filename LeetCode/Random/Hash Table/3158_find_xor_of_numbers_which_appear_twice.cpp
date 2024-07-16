class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        // Time: O(n), Space: O(n)
        unordered_map<int, int> ft;
        vector<int> duplicates;

        for(auto num: nums)
            ft[num]++;

        for(auto& [num, frequency]: ft)
            if(frequency == 2)
                duplicates.push_back(num);

        int result = 0;
        for(int i = 0; i < duplicates.size(); i++)
            result = result xor duplicates[i];

        return result;
    }
};