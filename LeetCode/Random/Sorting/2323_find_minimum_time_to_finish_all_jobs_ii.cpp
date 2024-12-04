class Solution {
public:
    int minimumTime(vector<int>& jobs, vector<int>& workers) {
        // Time: O(n), Space: O(n)
        std::sort(jobs.rbegin(), jobs.rend());
        std::sort(workers.rbegin(), workers.rend());

        int max_days = 0;
        for(int i = 0; i < workers.size(); i++){
            auto time = (jobs[i] / workers[i]) + (jobs[i] % workers[i] > 0);
            max_days = std::max(max_days, time);
        }

        return max_days;
    }
};