class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // Time: O(n), Space: O(n)
        unordered_map<int, int> in_degree;
        for(auto edge: edges){
            int from = edge[0];
            int to = edge[1];
            in_degree[from]++;
            in_degree[to]++;
        }
        auto max_cnt = INT_MIN;
        auto center = 0;
        for(auto&[node, cnt]: in_degree){
            if(cnt > max_cnt){
                center = node;
                max_cnt = cnt;
            }
        }

        return center;
    }
};