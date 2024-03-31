class Solution {
public:

    struct VectorToStringHasher {
        size_t operator()(const vector<int>& vec) const {
            // Time: O(1), Space: O(1) since there are 26 characters always
            string serializedVec;
            for(int num : vec)
                serializedVec += to_string(num) + ",";
            return hash<string>()(serializedVec);
        }
    };

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Time: O(nm), Space: O(nm)
        unordered_map<vector<int>, vector<string>, VectorToStringHasher> partitions;
        vector<vector<string>> result;

        for(auto& str: strs){
            vector<int> sorted = bucket_sort(str);
            partitions[sorted].push_back(str);
        }

        for(const auto &[key, value]: partitions)
            result.push_back(value);

        return result;
    }

    vector<int> bucket_sort(const string& str){
        // Time: O(m), Space: O(1) where m: avg length of strings
        vector<int> result(26, 0);

        for(auto letter: str)
            result[letter - 'a']++;

        return result;
    }
};