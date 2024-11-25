class Solution {
public:
    int minimumKeypresses(string s) {
        // Time: O(nlogn), Space: O(n)
        unordered_map<char, int> ft;
        for(auto letter: s)
            ft[letter]++;

        vector<int> sorted;
        for(auto&[ch, cnt]: ft)
            sorted.push_back(cnt);

        std::sort(sorted.begin(), sorted.end());
        std::reverse(sorted.begin(), sorted.end());

        int total_presses = 0;
        for(int i = 0; i < sorted.size(); i++){
            total_presses += sorted[i] * ((i / 9) + 1);
        }

        return total_presses;
    }
};