class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        // Time: O(n + m), Space: O(n)
        unordered_set<char> j_set;
        for(auto j: jewels)
            j_set.insert(j);

        auto cnt = 0;
        for(auto s: stones)
            if(j_set.find(s) != j_set.end())
                cnt++;

        return cnt;
    }
};