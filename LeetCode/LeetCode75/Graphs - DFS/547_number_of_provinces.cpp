class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // Time: O(n^2), Space: O(n)
        vector<bool> visited(isConnected.size(), false);
        auto province_count = 0;
        for(int i = 0; i < isConnected.size(); i++){
            if(visited[i])
                continue;
            province_count++;
            dfs(i, isConnected, visited);
        }

        return province_count;
    }

    void dfs(int vertex, const vector<vector<int>>& connections, vector<bool>& visited){
        visited[vertex] = true;
        for(int i = 0; i < connections[vertex].size(); i++)
            if(not visited[i] && connections[vertex][i] == 1)
                dfs(i, connections, visited);
    }

};