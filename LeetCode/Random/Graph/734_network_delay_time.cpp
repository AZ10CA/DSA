class Solution {
public:
    Solution(){
        cin.tie(nullptr);
        cout.tie(nullptr);
        std::ios::sync_with_stdio(false);
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Time: O(ve), Spacce: O(v)
        vector<int> dist(n, INT_MAX); // represents the distance from "src" to other nodes
        dist[k - 1] = 0;

        for(int i = 0; i < n; i++){
            vector<int> temp = dist;

            for(auto& edge: times){
                int from = edge[0] - 1, to = edge[1] - 1, cost = edge[2];
                // "src" cannot reach from
                if(dist[from] == INT_MAX)
                    continue;
                temp[to] = std::min(dist[from] + cost, temp[to]);
            }

            dist = temp;
        }

        auto sum = 0;
        for(auto time: dist){
            if(time == INT_MAX)
                return -1;
            sum = std::max(sum, time);
        }

        return sum;
    }
};