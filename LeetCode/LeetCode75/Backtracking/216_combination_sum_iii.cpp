class Solution {
public:

    void backtrack(int start, vector<int>& current_combo, vector<vector<int>>& result, int target, int k){
        if(current_combo.size() > k)
            return;

        if(current_combo.size() == k){
            auto sum = 0;
            for(auto el: current_combo)
                sum += el;

            if(sum == target)
                result.push_back(current_combo);

            return;
        }

        for(int i = start; i <= 9; i++){
            current_combo.push_back(i);
            backtrack(i + 1, current_combo, result, target, k);
            current_combo.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> combo;
        backtrack(1, combo, result, n, k);
        return result;
    }
};