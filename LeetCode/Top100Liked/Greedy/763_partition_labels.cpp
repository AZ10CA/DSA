class Solution {
public:
    vector<int> partitionLabels(string s) {
        // Time: O(n), Space: O(1)
        unordered_map<char, pair<int, int>> ranges;

        for(int i = 0; i < s.size(); i++){
            auto letter = s[i];
            if(ranges.find(letter) == ranges.end())
                ranges[letter] = {i, i};
            else
                ranges[letter] = {ranges[letter].first, i};
        }

        int idx = 1;
        int start = ranges[s[0]].first;
        int end = ranges[s[0]].second;
        vector<int> partitions;

        while(idx < s.size()){
            auto letter = s[idx];
            auto range = ranges[letter];
            if(range.first > end){
                partitions.push_back(end - start + 1);
                start = range.first;
                end = range.second;
            } else {
                end = std::max(end, range.second);
            }
            idx++;
        }

        partitions.push_back(end - start + 1);

        return partitions;
    }
};