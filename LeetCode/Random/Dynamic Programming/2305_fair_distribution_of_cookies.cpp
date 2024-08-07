class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        // Time: O(k^n), Space: O(nk)
        vector<int> dist(k, 0);
        int answer = INT_MAX;
        traverse(0, answer, dist, cookies);
        return answer;
    }

    void traverse(int idx, int& answer, vector<int>& dist, const vector<int>& cookies){
        if(idx == cookies.size()){
            int mx = INT_MIN;
            for(auto each: dist)
                mx = std::max(mx, each);
            answer = std::min(answer, mx);
            return;
        }

        for(int i = 0; i < dist.size(); i++){
            dist[i] += cookies[idx];
            traverse(idx + 1, answer, dist, cookies);
            dist[i] -= cookies[idx];
        }
    }
};