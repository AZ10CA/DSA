enum State {VISITED, VISITING, NOT_VISITED};

class Solution {
    unordered_map<int, vector<int>> graph;
    unordered_map<int, State> states;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Time: O(V + E), Space: O(V + E)
        // Phase 1: build the graph
        for(auto pre: prerequisites){
            auto from = pre[1], to = pre[0];
            graph[from].push_back(to);
            states[from] = states[to] = State::NOT_VISITED;
        }

        // Phase 2: Run DFS
        bool has_cycle = false;
        for(int i = 0; i < numCourses && !has_cycle; i++)
            if(graph.find(i) != graph.end() && states[i] == State::NOT_VISITED)
                dfs(i, has_cycle);

        // Phase 3: Check for cycle
        return !has_cycle;
    }

    void dfs(int vertex, bool& has_cycle){
        if(states[vertex] == State::VISITED)
            return;

        if(states[vertex] == State::VISITING  || has_cycle){
            has_cycle = true;
            states[vertex] = State::VISITED;
            return;
        }

        states[vertex] = State::VISITING;
        for(auto child: graph[vertex])
            dfs(child, has_cycle);

        states[vertex] = State::VISITED;
    }

};