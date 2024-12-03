class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // Time: O(n), Space: O(k)
        unordered_set<int> seen;
        list<int> subarray;
        long long sum = 0;
        long long answer = 0;

        for(int i = 0; i < nums.size(); i++){
            if(subarray.size() != k){
                while(seen.find(nums[i]) != seen.end()){
                    sum -= subarray.front();
                    seen.erase(subarray.front());
                    subarray.pop_front();
                }
                seen.insert(nums[i]);
                subarray.push_back(nums[i]);
                sum += nums[i];
            }

            if(subarray.size() == k){
                answer = std::max(answer, sum);
                auto first = subarray.front();
                subarray.pop_front();
                sum -= first;
                seen.erase(first);
            }
        }

        if(subarray.size() == k)
            answer = std::max(answer, sum);

        return answer;
    }
};