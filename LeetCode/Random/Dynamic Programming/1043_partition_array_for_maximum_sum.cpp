class Solution {
    vector<int> table;
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // Time: O(nk), Space: O(n)
        table = vector<int>(arr.size(), -1);
        return dp(0, k, arr);
    }

    int dp(int start, int k, const vector<int>& arr){
        if(start >= arr.size())
            return 0;

        auto& memo = table[start];
        if(memo != -1)
            return memo;

        int end = std::min(start + k - 1, (int)arr.size() - 1);
        int max_num = INT_MIN, ans = INT_MIN;
        for(int i = start; i < end + 1; i++){
            max_num = std::max(max_num, arr[i]);
            ans = std::max(max_num * (i - start + 1) + dp(i + 1, k, arr), ans);
        }

        return memo = ans;
    }
};