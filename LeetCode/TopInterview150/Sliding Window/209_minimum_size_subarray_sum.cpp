class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // Time: O(n), Space: O(1)
        int sum = 0, size = 0;
        int answer = INT_MAX;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            size++;
            while(sum >= target){
                answer = std::min(answer, size);
                sum -= nums[i - size + 1];
                size--;
            }
        }

        return answer == INT_MAX ? 0 : answer;
    }
};