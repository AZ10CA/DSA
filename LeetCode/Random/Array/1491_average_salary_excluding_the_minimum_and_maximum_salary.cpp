class Solution {
public:
    double average(vector<int>& salary) {
        // Time: O(n), Space: O(1)
        double mn = INT_MAX, mx = INT_MIN;
        for(auto s: salary){
            mn = s < mn ? s : mn;
            mx = s > mx ? s : mx;
        }

        double sum = 0;
        for(auto s: salary)
            sum += s;

        sum = sum - mn - mx;
        return sum / (salary.size() - 2);
    }
};