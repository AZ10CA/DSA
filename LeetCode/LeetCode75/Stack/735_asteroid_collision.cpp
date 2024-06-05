class Solution {
public:
    enum Direction {
        Left, Right
    };

    vector<int> asteroidCollision(vector<int>& asteroids) {
        // Time: O(n), Space: O(n)
        stack<int> st;
        for(int i = 0; i < asteroids.size(); i++){
            auto ast = asteroids[i];
            auto direction = ast > 0 ? Direction::Right : Direction::Left;
            auto mass = std::abs(ast);
            if(st.empty() || direction == Direction::Right)
                // if the direction is right or the Stack is empty we push the asteroid
                st.push(ast);
            else {
                // if direction is to the left, there could be collision
                auto top_mass= std::abs(st.top());
                auto top_direction = st.top() > 0 ? Direction::Right : Direction::Left;
                if(top_direction == Direction::Left)
                    st.push(ast);
                else {
                    if(top_mass == mass){
                        st.pop();
                        continue;
                    } else if(mass > top_mass){
                        st.pop();
                        i--;
                    }
                }
            }
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