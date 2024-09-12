class Solution {
public:
    int maxArea(vector<int>& heights) {
        // Time: O(n), Space: O(1)
        int left = 0, right = heights.size() - 1;
        int max_water = 0;

        while(left < right){
            int width = right - left;
            int height = std::min(heights[left], heights[right]);
            max_water = std::max(max_water, height * width);

            if(heights[left] < heights[right])
                left++;
            else
                right--;
        }

        return max_water;
    }
};