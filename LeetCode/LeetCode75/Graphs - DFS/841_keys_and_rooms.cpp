class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // Time: O(n + k), Space: O(n) n: rooms, k: keys
        vector<bool> visited(rooms.size(), false);
        dfs(0, rooms, visited);

        return std::all_of(visited.begin(), visited.end(), [](auto el){ return el == true; });
    }

    void dfs(int vertex, const vector<vector<int>>& rooms, vector<bool>& visited){
        visited[vertex] = true;
        for(auto child: rooms[vertex])
            if(!visited[child])
                dfs(child, rooms, visited);
    }
};