class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Time: O(n), Space: O(1)
        int closest = arr.size() / 2;
        binary_search(closest, x, arr);

        // now expand from the closest number
        vector<int> result;
        int left = closest - 1, right = closest + 1;
        k--;
        while(k--){
            auto left_value = left >= 0 ? arr[left] : -1e7 - 1;
            auto right_value = right < arr.size() ? arr[right] : 1e7 + 1;
            if(std::abs(left_value - x) <= std::abs(right_value - x))
                left--;
            else
                right++;
        }

        for(int i = left + 1; i < right; i++)
            result.push_back(arr[i]);

        return result;
    }


    // find the left most element in the array that is closest to target
    void binary_search(int& closest, int target, const vector<int>& arr){
        int left = 0, right = arr.size() - 1;
        while(left <= right){
            int middle = left + (right - left) / 2;
            int diff = std::abs(arr[middle] - target);
            int prev_diff = std::abs(arr[closest] - target);

            if(diff == prev_diff)
                closest = middle < closest ? middle : closest;
            if(diff < prev_diff)
                closest = middle;

            if(arr[middle] > target)
                right = middle - 1;
            else
                left = middle + 1;
        }
    }
};