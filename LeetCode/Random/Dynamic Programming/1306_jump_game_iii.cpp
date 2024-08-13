class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> table(arr.size(), -1);
        unordered_set<int> seen;
        return jump(start, seen, table, arr);
    }

    bool jump(int idx, unordered_set<int>& seen, vector<int>& table, const vector<int>& arr){
        // Time: O(n), Space: O(n)
        if(idx < 0 or idx >= arr.size() or seen.find(idx) != seen.end())
            return false;

        auto& memo = table[idx];
        if(memo != -1)
            return memo;

        if(arr[idx] == 0)
            return true;

        seen.insert(idx);

        auto can_jump = false;
        auto forward_idx = idx + arr[idx];
        if(forward_idx < arr.size())
            can_jump |= jump(forward_idx, seen, table, arr);

        auto backward_idx = idx - arr[idx];
        if(backward_idx >= 0)
            can_jump |= jump(backward_idx, seen, table, arr);

        seen.erase(idx);

        return memo = can_jump;
    }
};