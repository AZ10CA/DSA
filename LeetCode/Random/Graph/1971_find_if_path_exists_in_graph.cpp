class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Time: O(V+E), Space: O(V+E)
        vector<vector<int>> graph(n, vector<int>());
        for(auto edge: edges){
            auto from = edge[0];
            auto to = edge[1];
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        vector<bool> visited(n, false);
        queue<int> to_visit;
        to_visit.push(source);
        visited[source] = true;

        while(not to_visit.empty()){
            auto node = to_visit.front();
            to_visit.pop();
            if(node == destination)
                return true;

            for(auto child: graph[node])
                if(not visited[child]){
                    to_visit.push(child);
                    visited[child] = true;
                }
        }

        return false;
    }
};