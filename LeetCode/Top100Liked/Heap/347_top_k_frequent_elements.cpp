class Solution {
public:
    struct compare_pair {
        bool operator()(pair<int, int> first, pair<int, int> second){
            return first.second < second.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Time: O(nlogn + klogn), Space: O(m) where m: unique elements
        unordered_map<int, int> frequency_table;
        for(auto num: nums)
            frequency_table[num]++;

        priority_queue<pair<int, int>, std::vector<pair<int, int>>, compare_pair> pq;
        for(auto& [num, cnt]: frequency_table){
            pq.emplace(num, cnt);
        }
        vector<int> result;
        while(k--){
            result.push_back(pq.top().first);
            pq.pop();
        }

        return result;
    }
};