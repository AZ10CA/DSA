class Solution {
public:
    int getKth(int lo, int hi, int k) {
        // Time: O(nlogn), Space: O(n)
        unordered_map<int, int> table;
        for(int i = lo; i <= hi; i++)
            dp(i, table);
        
        vector<pair<int, int>> result;
        for(int i = lo; i <= hi; i++){
            auto num = i;
            auto power = table[num];
            result.emplace_back(num, power);
            }
        
        std::sort(result.begin(), result.end(), [](auto& f, auto& s){
            if(f.second == s.second)
                return f.first < s.first;
            
            return f.second < s.second;
        });

        return result[k - 1].first;
    }

    int dp(int num, unordered_map<int, int>& table){
        if(num == 1)
            return 0;
        
        if(table.find(num) != table.end())
            return table[num];

        table[num] = 1 + ((num & 1) ? dp(3 * num + 1, table) : dp(num / 2, table));
        return table[num];
    }
};
