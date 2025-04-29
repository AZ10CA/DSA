class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        // Time: O(n), Space: O(n)
        int cost = 0;
        auto distance = hamming_distance(0, 0, cost, s, t);
        return distance == 1;
    }

    bool hamming_distance(int s_idx, int t_idx, int cost, const string& s, const string& t){
        if(s_idx == s.size())
            return (cost + t.size() - t_idx) == 1;
        if(t_idx == t.size())
            return (cost + s.size() - s_idx) == 1;

        if(cost > 1)
            return false;

        if(s[s_idx] == t[t_idx])
            return hamming_distance(s_idx + 1, t_idx + 1, cost, s, t);

        // characters are not the same
        auto add = hamming_distance(s_idx, t_idx + 1, cost + 1, s, t);
        auto deletion = hamming_distance(s_idx + 1, t_idx, cost + 1, s, t);
        auto replace = hamming_distance(s_idx + 1, t_idx + 1, cost + 1, s, t);

        return add || deletion || replace;
    }
};