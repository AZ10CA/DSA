class Solution {
public:
    int minSwaps(vector<int>& data) {
        // Time: O(n), Space: O(n)
        int ones = 0, zeroes = 0;
        int sw_size = 0; // sliding window size

        for(auto each: data)
            sw_size += each; // count the number of 1s

        int answer = INT_MAX;
        for(int i = 0; i < data.size(); i++){
            ones += data[i];
            zeroes += data[i] == 0;

            if(ones + zeroes == sw_size){
                answer = std::min(answer, zeroes);
                // pop the first element
                auto first = data[i - sw_size + 1];
                zeroes -= first == 0;
                ones -= first;
            }
        }

        return answer == INT_MAX ? 0 : answer;
    }
};