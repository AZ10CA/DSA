class Solution {
    vector<vector<int>> table;
    unordered_map<int, vector<pair<int, int>>> graph;

public:
    /**
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Time: O(ke), Space: O(n)
        // Bellman-Ford Algorithm

        vector<int> dist(n, INT_MAX); // represents the distance from "src" to other nodes
        dist[src] = 0;


        // relax the nodes k + 1 times
        for(int i = 0; i < k + 1; i++){
            vector<int> temp = dist;

            for(auto& edge: flights){
                int from = edge[0], to = edge[1], cost = edge[2];
                // "src" cannot reach from
                if(dist[from] == INT_MAX)
                    continue;
                temp[to] = std::min(dist[from] + cost, temp[to]);
            }

            dist = temp;
        }


        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
    */

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Time: O(ek), Space: O(nk), where e: number of edges
        this->table = vector<vector<int>>(n, vector<int>(k + 1, -1));

        // create a weighted graph using the edge list
        for(auto& f: flights){
            int from = f[0], to = f[1], cost = f[2];
            graph[from].emplace_back(to, cost);
        }
        auto min_cost = dp(src, dst, k);
        return  min_cost == INT_MAX ? -1 : min_cost;
    }

    int dp(int src, int dest, int k){
        if(src == dest)
            return 0;

        if(k < 0)
            return INT_MAX;

        auto& memo = table[src][k];
        if(memo != -1)
            return memo;

        // find a path from neighbours to the dest that gives us the minimum cost
        int min_cost = INT_MAX;
        for(const auto& [to, price]: graph[src]){
            auto cost = dp(to, dest, k - 1); // cost to get to dest from neighbour
            if(cost == INT_MAX)
                continue;
            min_cost = std::min(cost + price, min_cost);
        }

        return memo = min_cost;
    }
};