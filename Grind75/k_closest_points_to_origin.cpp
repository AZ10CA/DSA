class Solution {
    struct Point {
        int x;
        int y;

        Point(int x, int y) : x(x), y(y) {}

        double distance() const {
            return sqrt(x * x + y * y);
        }

        vector<int> to_vector() const {
            return {x, y};
        }

        bool operator<(const Point &other) {
            return distance() < other.distance();
        }

        struct ComparePoints {
            bool operator()(const Point &first, const Point &second) {
                return first.distance() < second.distance();
            }
        };
    };

public:
    vector <vector<int>> kClosest(vector <vector<int>> &points, int k) {
        // Time: O(nlogk), Space: O(k)
        priority_queue <Point, std::vector<Point>, Point::ComparePoints> heap;

        for (auto point: points) {
            Point p(point[0], point[1]);
            if (heap.size() != k)
                heap.push(p);
            else {
                if (p.distance() < heap.top().distance()) {
                    heap.pop();
                    heap.push(p);
                }
            }
        }

        vector <vector<int>> result;
        while (!heap.empty()) {
            result.push_back(heap.top().to_vector());
            heap.pop();
        }

        return result;
    }
};