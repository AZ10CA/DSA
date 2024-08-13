class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        vector<int> table(arr.size(), -1);
        for(int i = 0; i < arr.size(); i++)
            jump(i, d, arr, table);

        int mx = INT_MIN;
        for(auto each: table)
            mx = std::max(mx, each);

        return mx;
    }


    int jump(int idx, const int d, const vector<int>& arr, vector<int>& table){
        // Time: O(nd), Space: O(n)
        if(idx < 0 || idx >= arr.size())
            return INT_MIN;

        int left_bar = idx == 0 ? INT_MAX : arr[idx - 1];
        int right_bar = idx == arr.size() - 1 ? INT_MAX : arr[idx + 1];

        auto& memo = table[idx];
        if(memo != -1)
            return memo;

        if(left_bar >= arr[idx] && right_bar >= arr[idx])
            return memo = 1;

        int seen = 1;
        // right side jumps
        for(int i = idx + 1; i < arr.size() && i <= idx + d; i++){
            if(arr[i] >= arr[idx])
                break;
            seen = std::max(seen, 1 + jump(i, d, arr, table));
        }

        // left side jumps
        for(int i = idx - 1; i >= 0 && i >= idx - d; i--){
            if(arr[i] >= arr[idx])
                break;
            seen = std::max(seen, 1 + jump(i, d, arr, table));
        }

        return memo = seen;
    }

};
