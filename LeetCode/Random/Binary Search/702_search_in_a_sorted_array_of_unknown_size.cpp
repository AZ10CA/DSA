/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        // Time: O(logn), Space: O(1)
        int left = 0, right = 1e4;
        while(left <= right){
            auto middle = left + (right - left) / 2;
            auto num = reader.get(middle);
            if(num == target)
                return middle;

            if(num == INT_MAX || num > target)
                right = middle - 1;
            else
                left = middle + 1;
        }

        return -1;
    }
};