class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Time: O(n), Space: O(n), n: sum of the length of all strings in "strs"
        vector<string> sorted;
        vector<vector<string>> result;
        unordered_map<string, vector<string>> groups;

        for(int i = 0; i < strs.size(); i++)
            groups[bucket_sort(strs[i])].push_back(strs[i]);

        for(auto&[key, members]: groups)
            result.push_back(members);

        return result;
    }

    string bucket_sort(const string& str){
        // Time: O(n), Space: O(n)
        array<int, 26> ft{0};
        for(auto letter: str)
            ft[letter - 'a']++;

        string sorted;
        int idx = 0;

        for(int i = 0; i < 26; i++){
            if(ft[i] == 0)
                continue;

            auto letter = i + 'a';
            for(int j = 0; j < ft[i]; j++)
                sorted += letter;
        }

        return sorted;
    }
};