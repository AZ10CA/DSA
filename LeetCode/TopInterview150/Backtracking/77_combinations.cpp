class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        // Time: O(nCk), Space: O(k * nCk)
        vector<int> current;
        vector<vector<int>> result;

        backtrack(1, current, result, k, n);

        return result;
    }

    void backtrack(int start, vector<int>& current, vector<vector<int>>& result, int k, int n){
        if(current.size() == k)
            result.push_back(current);
        else {
            for(int i = start; i <= n; i++){
                // take the number
                current.push_back(i);
                backtrack(i + 1, current, result, k, n);
                current.pop_back();
            }
        }
    }
};