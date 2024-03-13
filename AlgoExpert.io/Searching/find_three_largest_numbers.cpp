#include <vector>
#include <queue>

using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array) {
    // Time: O(n), Space: O(1)
    priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (auto element: array)
        if (pq.size() < 3)
            pq.push(element);
        else if (pq.top() < element) {
            pq.pop();
            pq.push(element);
        }
    vector<int> result;
    while (not pq.empty()) {
        result.push_back(pq.top());
        pq.pop();
    }
    return result;
}
