class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> table(days.size(), -1);
        return dp(0, table, days, costs);
    }

    int dp(int day_idx, vector<int>& table, const vector<int>& days, const vector<int>& costs){
        // Time: O(n), Space: O(n)
        if(day_idx == days.size())
            return 0;

        if(table[day_idx] != -1)
            return table[day_idx];

        auto& current_day = days[day_idx];
        auto take_1 = costs[0] + dp(day_idx + 1, table, days, costs);

        int i = day_idx;
        while(i < days.size() && current_day + 7 > days[i])
            i++;
        auto take_7 = costs[1] + dp(i, table, days, costs);

        i = day_idx;
        while(i < days.size() && current_day + 30 > days[i])
            i++;

        auto take_30 = costs[2] + dp(i, table, days, costs);

        return table[day_idx] = std::min(take_1, std::min(take_7, take_30));
    }
};