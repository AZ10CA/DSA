class Solution {
public:
    int titleToNumber(string columnTitle) {
        int power = columnTitle.size() - 1;
        int sum = 0;
        for(auto ch: columnTitle){
            auto num = get_value(ch);
            sum += num * std::pow(26, power--);
        }

        return sum;
    }

    int get_value(char ch){
        return ch - 'A' + 1;
    }
};