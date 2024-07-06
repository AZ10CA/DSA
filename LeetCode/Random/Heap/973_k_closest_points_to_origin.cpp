struct Distance {
    int x, y;
    double distance;

    Distance(int x, int y): x(x), y(y){
        distance = std::sqrt(std::pow(x, 2) + std::pow(y, 2));
    }

    bool operator<(const Distance& second) const {
        return distance < second.distance;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Time: O(nlogk), Space: O(k)
        priority_queue<Distance> distances;

        for(auto point: points){
            int x = point[0];
            int y = point[1];
            Distance dist(x, y);
            if(distances.size() < k)
                distances.push(dist);
            else if(distances.top().distance > dist.distance){
                distances.pop();
                distances.push(dist);
            }
        }

        vector<vector<int>> result;
        while(distances.size()){
            result.push_back({distances.top().x, distances.top().y});
            distances.pop();
        }

        return result;
    }
};