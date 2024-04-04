class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        // Time: O(n), Space: O(1)
        int max_sum = 0;
        int running_sum = 0;
        for(auto g: gain){
            running_sum += g;
            max_sum = std::max(max_sum, running_sum);
        }

        return max_sum;
    }
};