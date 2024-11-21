class Solution {
public:
    Solution(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
    }

    int trap(vector<int>& height) {
        // Time: O(n), Space: O(n)
        int sz = height.size();
        vector<int> l_max(sz, 0), r_max(sz, 0);

        for(int i = 1; i < height.size(); i++)
            l_max[i] = std::max(l_max[i - 1], height[i - 1]);

        for(int i = height.size() - 2; i >= 0; i--)
            r_max[i] = std::max(r_max[i + 1], height[i + 1]);

        int water = 0;
        for(int i = 0; i < height.size(); i++)
            water += std::max(std::min(l_max[i], r_max[i]) - height[i], 0);

        return water;
    }
};