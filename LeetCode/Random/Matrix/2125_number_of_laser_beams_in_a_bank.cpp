class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        // Time: O(mn), Space: O(1)
        auto last_device_count = 0;
        auto sum = 0;

        for(int i = 0; i < bank.size(); i++){
            auto count = count_devices(bank[i]);
            if(count == 0)
                continue;

            sum += last_device_count * count;
            last_device_count = count;
        }

        return sum;
    }

    int count_devices(const string& str){
        auto cnt = 0;

        for(auto ch: str)
            cnt += ch == '1';

        return cnt;
    }
};