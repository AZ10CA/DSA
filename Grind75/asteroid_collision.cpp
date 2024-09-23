class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // Time: O(n), Space: O(n)
        int idx = 0;
        stack<int> st;

        while(idx < asteroids.size()){
            if(st.empty() || asteroids[idx] > 0){
                st.push(asteroids[idx++]);
                continue;
            }

            // asteroid going left
            auto last_asteroid = st.top();
            if(last_asteroid < 0){
                // both going left, they won't collide
                st.push(asteroids[idx++]);
            } else if(last_asteroid == -asteroids[idx]){
                // the same size, pop the last asteroid
                st.pop();
                idx++;
            } else if(last_asteroid > -asteroids[idx]){
                // the last asteroid destroys the new one
                idx++;
            } else
                // the new asteroid is bigger so, it replaces the last one
                st.pop();
        }

        vector<int> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }

        std::reverse(result.begin(), result.end());

        return result;
    }
};