class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Time: O(n), Space: O(1)
        int sum = 0;

        for(int i = 0; i < gas.size(); i++)
            sum += gas[i] - cost[i];

        if(sum < 0)
            return -1;

        int tank = 0;
        int starting_city = 0;

        for(int i = 0; i < gas.size(); i++){
            auto benefit = gas[i] - cost[i];
            tank += benefit;

            if(tank < 0){
                starting_city = i + 1;
                tank = 0;
            }
        }

        return starting_city;
    }
};