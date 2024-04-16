class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        // Time: O(n), Space: O(n)
        vector<int> result(temps.size(), 0);
        stack<pair<int, int>> mono;
        for(int i = 0; i < temps.size(); i++){
            if(mono.empty() || mono.top().first >= temps[i])
                mono.emplace(temps[i], i);
            else {
                while(mono.size() && temps[i] > mono.top().first){
                    int diff = i - mono.top().second;
                    result[mono.top().second] = diff;
                    mono.pop();
                }

                mono.emplace(temps[i], i);
            }
        }

        return result;
    }
};