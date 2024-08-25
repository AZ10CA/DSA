class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        // Time: O(n), Space: O(n)
        vector<int> w(accounts.size());
        for(auto acc: accounts){
            auto sum = 0;
            for(auto money: acc)
                sum += money;
            w.push_back(sum);
        }

        int mx = INT_MIN;
        for(auto each: w)
            mx = std::max(mx, each);

        return mx;
    }
};