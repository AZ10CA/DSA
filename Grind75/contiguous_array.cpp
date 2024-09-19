class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // Time: O(n), Space: O(n)
        int counter = 0, answer = 0;
        unordered_map<int, int> map; // count to idx
        map[0] = -1;

        for(int i = 0; i < nums.size(); i++){
            counter += nums[i] == 1 ? 1 : -1;
            if(map.find(counter) != map.end())
                answer = std::max(answer, i - map[counter]);
            else
                map[counter] = i;

        }

        return answer;
    }
};