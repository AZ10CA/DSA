class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Time: O(nlogn + mlogm), Space: O(1)
        std::sort(s.begin(), s.end());
        std::sort(g.begin(), g.end());

        int cnt = 0;
        int child_idx = 0, cookie_idx = 0;
        while(child_idx < g.size() && cookie_idx < s.size()){
            if(s[cookie_idx] >= g[child_idx]){
                cnt++;
                child_idx++;
                cookie_idx++;
            } else
                cookie_idx++;
        }

        return cnt;
    }
};