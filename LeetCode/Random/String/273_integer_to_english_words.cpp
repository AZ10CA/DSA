class Solution {
    unordered_map<int, string> num_str = {
            {0, ""},
            {1, "One"},
            {2, "Two"},
            {3, "Three"},
            {4, "Four"},
            {5, "Five"},
            {6, "Six"},
            {7, "Seven"},
            {8, "Eight"},
            {9, "Nine"},
    };

    unordered_map<int, string> one_tens {
            {0, "Ten"},
            {1, "Eleven"},
            {2, "Twelve"},
            {3, "Thirteen"},
            {4, "Fourteen"},
            {5, "Fifteen"},
            {6, "Sixteen"},
            {7, "Seventeen"},
            {8, "Eighteen"},
            {9, "Nineteen"},
    };

    unordered_map<int, string> tens = {
            {2, "Twenty"},
            {3, "Thirty"},
            {4, "Forty"},
            {5, "Fifty"},
            {6, "Sixty"},
            {7, "Seventy"},
            {8, "Eighty"},
            {9, "Ninety"}
    };

    vector<pair<int, string>> units = {
            {99, ""},
            {999, "Thousand "},
            {999999, "Million "},
            {999999999, "Billion "},
    };

public:
    string numberToWords(int num) {
        // Time: O(n), Space: O(n)
        string num_str = to_string(num);
        vector<string> partitions = split(num_str);

        int unit_idx = 0;
        for(int i = 0; i < units.size(); i++)
            if(num > units[i].first)
                unit_idx = i;

        string result;
        for(auto partition: partitions){
            auto first_half = read(partition);
            result += first_half;
            cout << result << endl;
            if(first_half.empty()){
                unit_idx--;
                continue;
            }
            auto second_half = units[unit_idx].second;
            if(!second_half.empty())
                result += " " + second_half;
            unit_idx--;
        }

        if(result.back() == ' ')
            result.pop_back();

        return result;
    }

    vector<string> split(const string& str){
        vector<string> result;
        string current;
        for(int i = str.size() - 1; i >= 0; i--){
            if(current.size() == 3){
                result.push_back(current);
                current = "";
            }

            current.insert(current.begin(), str[i]);
        }

        if(current.size())
            result.push_back(current);


        std:reverse(result.begin(), result.end());

        return result;
    }

    string read_two(string str){
        if(str[0] == '1')
            return one_tens[str[1] - '0'];
        if(str[0] == '0')
            return num_str[str[1] - '0'];

        auto first_half = tens[str[0] - '0'];
        auto second_half = num_str[str[1] - '0'];
        if(second_half.empty())
            return first_half;

        return first_half + " " + second_half;
    }

    string read(string str){
        if(str == "0")
            return "Zero";

        while(str.front() == '0')
            str.erase(str.begin());

        if(str.size() == 1)
            return num_str[str[0] - '0'];

        if(str.size() == 2)
            return read_two(str);

        if(str.size() == 3){
            auto first_half = num_str[str[0] - '0'] + " Hundred";
            auto second_half = read_two(str.substr(1, 2));
            if(second_half.empty())
                return first_half;
            return first_half + " " + second_half;
        }

        return "";
    }

};