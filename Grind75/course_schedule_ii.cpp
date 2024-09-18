class Solution {
public:
    vector<int> findOrder(const int n, vector<vector<int>>& pre) {
        // Time: O(V + E), Space: O(V + E)
        vector<int> in_degree(n, 0);
        vector<vector<int>> graph(n);
        queue<int> to_visit;


        // convert to adjacency list
        for(auto& edge: pre){
            auto from = edge[1];
            auto to = edge[0];
            graph[from].push_back(to);
            in_degree[to]++;
        }


        // start traversing from the leaves
        for(int i = 0; i < in_degree.size(); i++)
            if(in_degree[i] == 0)
                to_visit.push(i);


        vector<int> order;
        while(not to_visit.empty()){
            auto top = to_visit.front();
            to_visit.pop();

            order.push_back(top);

            for(auto& child: graph[top]){
                in_degree[child]--;
                if(in_degree[child] == 0)
                    to_visit.push(child);
            }
        }

        // make sure all courses are taken
        bool is_possible = order.size() == n;

        return is_possible ? order : vector<int>();
    }
};