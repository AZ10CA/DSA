enum Color {
    RED,
    BLUE,
    WHITE
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // Time: O(V+E), Space: O(V)
        vector<Color> colors(graph.size(), Color::WHITE);
        for(int i = 0; i < graph.size(); i++)
            if(!bfs(i, colors, graph))
                return false;

        return true;
    }

    bool bfs(int node, vector<Color>& colors, const vector<vector<int>>& graph){
        if(colors[node] != Color::WHITE)
            return true;

        queue<int> to_visit;
        to_visit.push(node);
        colors[node] = Color::RED;

        while(!to_visit.empty()){
            auto top = to_visit.front();
            to_visit.pop();
            auto self_color = colors[top];

            for(auto neighbour: graph[top]){
                if(colors[neighbour] == Color::WHITE){
                    colors[neighbour] = opposite_color(self_color);
                    to_visit.emplace(neighbour);
                } else if(!is_opposite_color(self_color, colors[neighbour]))
                    return false;
            }
        }

        return true;
    }


    bool is_opposite_color(Color first, Color second){
        return (first == Color::RED && second == Color::BLUE) || (first == Color::BLUE && second == Color::RED);
    }

    Color opposite_color(Color color){
        return color == Color::RED ? Color::BLUE : Color::RED;
    }
};