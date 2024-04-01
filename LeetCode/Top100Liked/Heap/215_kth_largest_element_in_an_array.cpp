class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Time: O(nlogk), Space: O(k)
        priority_queue<int, vector<int>, std::greater<int>> pq;
        for(auto num: nums)
            if(pq.size() < k)
                pq.push(num);
            else {
                auto top = pq.top();
                if(num > top){
                    pq.pop();
                    pq.push(num);
                }
            }

        return pq.top();
    }
};