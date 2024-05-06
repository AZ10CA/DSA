class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Time: O(n), Space: O(1)
        auto sum = 0;
        for(int i = 0; i < gas.size(); i++)
            sum += gas[i] - cost[i];

        if(sum < 0)
            return -1;

        int current_gas = 0;
        int starting_position = 0;
        for(int i = 0; i < gas.size(); i++){
            current_gas += gas[i] - cost[i];
            if(current_gas < 0){
                // if index i was the answer, the current_gas would never reach below zero
                current_gas = 0;
                starting_position = i + 1;
            }
        }

        return starting_position;
    }
};