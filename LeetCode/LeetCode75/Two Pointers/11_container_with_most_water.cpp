class Solution {
public:
    int maxArea(vector<int>& height) {
        // Time: O(n), Space: O(1)
        int fp = 0, sp = height.size() - 1;
        int max_water = 0;

        while(fp < sp){
            max_water = std::max(water_volume(fp, sp, height), max_water);
            if(height[fp] < height[sp])
                fp++;
            else
                sp--;
        }

        return max_water;
    }

    int water_volume(int first, int second, const vector<int>& height){
        return std::min(height[second], height[first]) * (second - first);
    }
};