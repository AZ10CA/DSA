class Solution {
public:
    bool dfs(int course, vector<vector<int>>& graph, vector<int>& visited){
        if(visited[course] == 1) return false;
        if(visited[course] == 2) return true;

        visited[course] = 1;

        for(auto child: graph[course])
            if(!dfs(child, graph, visited))
                return false;

        visited[course] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> visited(numCourses);

        for(auto pre: prerequisites)
            graph[pre[1]].push_back(pre[0]);

        for(int i = 0; i < numCourses; i++){
            if(dfs(i, graph, visited) == false)
                return false;
        }

        return true;
    }
};