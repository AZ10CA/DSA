class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        // Time: O(n), Space: O(n)
        unordered_map<string, int> ft;
        for(auto str: arr)
            ft[str]++;

        for(auto str: arr){
            if(ft.find(str) == ft.end() || ft[str] > 1)
                continue;
            k--;
            if(k == 0)
                return str;
        }

        return "";
    }
};