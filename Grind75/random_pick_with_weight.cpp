class Solution {
    int min;
    int max;

    vector<pair<int, int>> ranges;
    std::mt19937 gen; // Random number generator
    std::uniform_int_distribution<> distrib; // Distribution
public:
    Solution(vector<int>& w): gen(std::random_device{}()) {
        // Time: O(n), Space: O(n)
        this->min = 0;

        int last_end = -1;
        for(int i = 0; i < w.size(); i++){
            last_end++;
            auto new_end = last_end + w[i] - 1;
            ranges.emplace_back(last_end, new_end);
            last_end = new_end;
        }

        this->max = last_end;
        this->distrib = std::uniform_int_distribution<>(min, max);
    }

    int pickIndex() {
        // Time: O(logn), Space: O(1)
        int random_num = distrib(gen); // Reuse the pre-initialized generator and distribution
        auto idx = binary_search(random_num);

        return idx;
    }

    int binary_search(int target){
        int left = 0, right = ranges.size() - 1;
        while(left <= right){
            auto middle = left + (right - left) / 2;
            const auto& range = ranges[middle];
            if(target >= range.first && target <= range.second)
                return middle;

            if(target > range.second)
                left = middle + 1;
            else
                right = middle - 1;
        }

        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

/**
   1, 3 -> 0.25, 0.75 -> 0, 1, 1, 1 -> pick randomly (25%) built-in C++ random function
   0 -> 0 -> erase O(1)
   1 -> 2
*/
