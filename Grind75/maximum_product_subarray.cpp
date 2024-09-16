class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Time: O(n), Space: O(1)
        int max_product = 1, min_product = 1, answer = *std::max_element(nums.begin(), nums.end());

        for(auto num: nums){
            if(num == 0){
                max_product = 1;
                min_product = 1;
                continue;
            }

            int temp = max_product;
            max_product = std::max({max_product * num, min_product * num, num});
            min_product = std::min({temp * num, min_product * num, num});

            answer = std::max(max_product, answer);
        }

        return answer;
    }
};