class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Time: O(nlogk), Space: O(k)
        priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        for(int i = 0; i < nums.size(); i++){
            if(minHeap.size() < k)
                minHeap.push(nums[i]);
            else {
                auto minElement = minHeap.top();
                if(minElement < nums[i]){
                    minHeap.pop();
                    minHeap.push(nums[i]);
                }
            }
        }

        return minHeap.top();
    }
};