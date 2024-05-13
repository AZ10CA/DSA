class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        // Time: O(n), Space: O(n)
        unordered_map<int, vector<int>> groups;
        vector<vector<int>> result;

        for(int i = 0; i < groupSizes.size(); i++){
            auto size = groupSizes[i];
            if(groups[size].size() < size)
                groups[size].push_back(i);
            else {
                result.push_back(groups[size]);
                groups[size].clear();
                groups[size].push_back(i);
            }
        }

        for(auto&[size, members]: groups)
            result.push_back(members);

        return result;
    }
};