class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // Time: O(nlogn), Space: O(n)
        map<int, int> table;
        for(auto& inter: intervals){
            auto start = inter[0], end = inter[1];
            table[start]++;
            table[end]--;
        }

        int collisions = 0;
        int max_collisions = 0;

        for(auto& [point, counter]: table){
            collisions += counter;
            max_collisions = std::max(max_collisions, collisions);
        }

        return max_collisions;
    }
};