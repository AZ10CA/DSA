class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        // Time: O(n), Space: O(n)
        unordered_set<string> all, starting;
        for(auto& path: paths){
            auto from = path[0], to = path[1];
            all.insert(from);
            starting.insert(to);
        }

        for(auto& each: starting)
            if(all.find(each) == all.end())
                return each;

        return "";
    }
};