class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        // Time: O(n), Space: O(1)
        unordered_map<int, int> seen;
        int count = 0;

        for(auto& hour: hours){
            hour %= 24;
            auto complement = (24 - hour) % 24;
            if(seen.find(complement) != seen.end())
                count += seen[complement];
            seen[hour]++;
        }

        return count;
    }
};