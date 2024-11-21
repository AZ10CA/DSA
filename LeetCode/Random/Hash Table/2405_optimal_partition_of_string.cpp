class Solution {
public:
    int partitionString(string s) {
        // Time: O(n), Space: O(n)
        int partitions = 1;
        unordered_set<char> seen;

        for(int i = 0; i < s.size(); i++){
            if(seen.find(s[i]) == seen.end()){
                seen.insert(s[i]);
            } else {
                seen.clear();
                seen.insert(s[i]);
                partitions++;
            }
        }

        return partitions;
    }
};