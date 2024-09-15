class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        // Time: O(n), Space: O(n)
        stack<pair<int, int>> monotonic;

        for(int i = temps.size() - 1; i >= 0; i--){
            if(monotonic.empty()){
                monotonic.emplace(temps[i], i);
                temps[i] = 0;
            } else {
                while(!monotonic.empty() && monotonic.top().first <= temps[i])
                    monotonic.pop();

                if(monotonic.empty()){
                    monotonic.emplace(temps[i], i);
                    temps[i] = 0;
                } else {
                    auto temp = temps[i];
                    temps[i] = monotonic.top().second - i;
                    monotonic.emplace(temp, i);
                }
            }
        }

        return temps;
    }
};