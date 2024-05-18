class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // Time: O(n * m), Space: O(n), m: average string size
        unordered_map<char, int> count;

        // count the total number of items for each type
        for(int i = 0; i < garbage.size(); i++){
            for(auto type: garbage[i])
                count[type]++;
        }

        vector<int> travel_time_prefix(garbage.size(), 0);
        for(int i = 1; i < garbage.size(); i++)
            travel_time_prefix[i] = travel_time_prefix[i - 1] + travel[i - 1];

        unordered_map<char, int> right_most;
        for(int i = 0; i < garbage.size(); i++){
            for(auto type: garbage[i])
                right_most[type] = i;
        }

        auto time = 0;
        for(auto&[type, index]: right_most)
            time += travel_time_prefix[index] + count[type];


        return time;
    }
};