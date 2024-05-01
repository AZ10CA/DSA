#define Graph unordered_map<string, vector<pair<string, double>>>
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Time: O(q * (v + e)), Space: O(v + e)
        Graph graph;
        vector<double> result;

        auto idx = 0;
        for(auto& eq: equations){
            auto from = eq[0], to = eq[1];
            auto weight = values[idx];
            idx++;
            graph[from].emplace_back(to, weight);
            graph[to].emplace_back(from, 1 / weight);
        }

        for(auto& q: queries){
            auto& from = q[0], &to = q[1];
            if(graph.find(from) == graph.end() || graph.find(to) == graph.end())
                result.push_back(-1);
            else {
                unordered_set<string> visited;
                auto product = dfs(from, to, graph, visited);
                result.push_back(product);
            }
        }

        return result;
    }

    double dfs(const string& from, const string& to, const Graph& graph, unordered_set<string>& visited){
        if(from == to)
            return 1;
        visited.insert(from);
        for(auto& vertex: graph.at(from)){
            auto node = vertex.first;
            auto weight = vertex.second;
            if(visited.find(node) == visited.end()){
                auto product = dfs(node, to, graph, visited);
                if(product != -1)
                    return product * weight;
            }
        }

        return -1;
    }
};