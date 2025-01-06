int PRIME = 40001;
class Solution {
public:
    Solution(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
    }
    int minAreaRect(vector<vector<int>>& pts) {
        int min_area = INT_MAX;
        unordered_set<int> points_set;

        for(auto pt: pts)
            points_set.insert(hash(pt));

        for(int i = 0; i < pts.size(); i++){
            auto from = pts[i];
            for(int j = i + 1; j < pts.size(); j++){
                auto to = pts[j];
                if(can_form(from, to, points_set)){
                    min_area = std::min(min_area, get_area(from, to));
                }
            }
        }

        return min_area == INT_MAX ? 0 : min_area;
    }

    int hash(const vector<int>& point){
        return point[0] * PRIME + point[1];
    }

    int get_area(vector<int>& from, vector<int>& to){
        return std::abs((to[1] - from[1]) * (to[0] - from[0]));
    }

    bool can_form(const vector<int>& from, const vector<int>& to, const unordered_set<int>& points_set){
        return (from[0] != to[0] && from[1] != to[1]) && points_set.find(hash({from[0], to[1]})) != points_set.end() &&
               points_set.find(hash({to[0], from[1]})) != points_set.end();

    }
};