class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Time: O(nlognm), Space: O(nm), n: nums.size(), m: average length of strings
        vector<string> str_nums;
        for(auto num: nums)
            str_nums.push_back(to_string(num));

        std::sort(str_nums.begin(), str_nums.end(), [](const string& first, const string& second){
            return first + second > second + first;
        });

        string result;
        for(auto num: str_nums)
            result += num;

        if(str_nums[0] == "0")
            return "0";

        return result;
    }
};
