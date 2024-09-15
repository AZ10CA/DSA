class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Time: O(n), Space: O(n)
        int sum = 0;
        vector<int> cities;

        for(int i = 0; i < gas.size(); i++){
            sum += gas[i] - cost[i];
            cities.push_back(gas[i] - cost[i]);
        }

        if(sum < 0)
            return -1;

        int tank = 0;
        int starting_city = -1;

        for(int i = 0; i < cities.size(); i++){
            if(tank <= 0){
                if(cities[i] < 0){
                    starting_city = -1;
                    tank = 0;
                } else {
                    starting_city = i;
                    tank = cities[i];
                }
            } else {
                tank += cities[i];
            }
        }

        return starting_city;
    }
};