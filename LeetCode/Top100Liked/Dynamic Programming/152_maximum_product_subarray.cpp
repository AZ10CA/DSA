class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // TIme: O(n), Space: O(1)
        int min_product = nums[0], max_product = nums[0];
        int answer = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < 0)
                std::swap(min_product, max_product);

            max_product = std::max(nums[i], max_product * nums[i]);
            min_product = std::min(nums[i], min_product * nums[i]);
            answer = std::max(answer, max_product);
        }

        return answer;
    }
};
