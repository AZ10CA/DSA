class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // Time: O(n), Space: O(1)
        auto cnt = 0;
        for(int i = 0; i < flowerbed.size(); i++){
            auto& current = flowerbed[i];
            auto left = i == 0 ? 0 : flowerbed[i - 1];
            auto right = i == flowerbed.size() - 1 ? 0 : flowerbed[i + 1];
            auto can_put = left == 0 && right == 0 && current == 0;
            if(can_put){
                current = 1;
                cnt++;
            }
        }

        return cnt >= n;
    }
};