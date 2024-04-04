class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Time: O(n), Space: O(n)
        unordered_map<int, int> ft; // frequency table
        for(auto num: arr)
            ft[num]++;

        unordered_set<int> seen;
        for(auto &[num, frequency]: ft){
            if(seen.find(frequency) != seen.end())
                return false;

            seen.insert(frequency);
        }

        return true;
    }
};