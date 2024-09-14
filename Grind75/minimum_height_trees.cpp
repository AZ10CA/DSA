class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n < 2)
            return {0};

        // Phase 1: create an adjacency list and determine the degree for each node
        vector<int> result;
        vector<int> degree(n, 0);
        vector<vector<int>> aj(n, vector<int>());

        for(auto& edge: edges){
            auto first = edge[0], second = edge[1];
            aj[first].push_back(second);
            aj[second].push_back(first);
            degree[first]++;
            degree[second]++;
        }


        // Phase 2: push the leaf nodes
        queue<int> to_visit;
        for(int i = 0; i < n; i++)
            if(degree[i] == 1)
                to_visit.push(i);


        // Phase 3: peel layer by layer
        while(n > 2){
            int level_size = to_visit.size();
            n -= level_size;
            while(level_size--){
                auto top = to_visit.front();
                to_visit.pop();

                for(auto neighbour: aj[top]){
                    degree[neighbour]--;
                    if(degree[neighbour] == 1)
                        to_visit.push(neighbour);
                }
            }
        }

        // Phase 4: return centroids (the remaining nodes)
        while(!to_visit.empty()){
            result.push_back(to_visit.front());
            to_visit.pop();
        }

        return result;
    }
};