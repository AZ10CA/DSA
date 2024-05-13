class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        // Time: O(nlogn), Space: O(n)
        vector<pair<int, string>> height_name;
        for(int i = 0; i < heights.size(); i++)
            height_name.emplace_back(heights[i], names[i]);

        std::sort(height_name.begin(), height_name.end(), [](auto& first, auto& second){
            return first.first > second.first;
        });

        vector<string> result;
        for(int i = 0; i < height_name.size(); i++)
            result.push_back(height_name[i].second);

        return result;
    }
};