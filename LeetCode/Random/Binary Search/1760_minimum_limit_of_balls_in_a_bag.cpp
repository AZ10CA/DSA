class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        // Time: O(nlogn), Space: O(1)
        int max_num = *std::max_element(nums.begin(), nums.end());
        int left = 1, right = max_num;
        int answer = INT_MAX;

        while(left <= right){
            auto mid = left + (right - left) / 2;
            if(canAchieve(mid, nums, maxOperations)){
                right = mid - 1;
                answer = mid;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }

    bool canAchieve(int penalty, const vector<int>& nums, int operations){
        for(auto num: nums)
            if(num > penalty)
                operations -= (num - 1) / penalty;


        return operations >= 0;
    }
};