#include <vector>

using namespace std;

int dp(int idx, int current_day, const vector<unordered_map<string, int>> &jobs, vector<vector<int>> &memo) {
    if (current_day > 7 || idx >= jobs.size())
        return 0;

    auto &m = memo[idx][current_day];
    if (m != -1)
        return m;

    auto current_job = jobs[idx];
    auto take = 0;

    if (current_day <= current_job["deadline"])
        take = current_job["payment"] + dp(idx + 1, current_day + 1, jobs);

    auto skip = dp(idx + 1, current_day, jobs);

    return m = std::max(skip, take);
}

int optimalFreelancing(vector<unordered_map<string, int>> jobs) {
    // Time: O(nlogn), Space: O(n)
    // NOTE: since current_day can't pass 7, the DP approach is sufficient for this problem since it gives O(7 * n) time complexity
    vector<vector<int>> memo(jobs.size(), vector<int>(7, -1));

    std::sort(jobs.begin(), jobs.end(), [](auto first, auto second) {
        return first["deadline"] <= second["deadline"];
    });

    return dp(0, 1, jobs, memo);
}
