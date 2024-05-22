#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    static void generate(int idx, vector<string> &segments, unordered_set<string> &result, const string &input) {
        if (segments.size() == 4 && idx == input.size()) {
            auto is_valid = true;
            for (const auto& seg: segments)
                is_valid &= isValidSegment(seg);
            if (is_valid)
                result.insert(segments[0] + "." + segments[1] + "." + segments[2] + "." + segments[3]);
        } else {
            for (int i = 1; i <= 3 && idx + i <= input.size(); i++) {
                auto segment = input.substr(idx, i);
                segments.push_back(segment);
                generate(idx + i, segments, result, input);
                segments.pop_back();
            }
        }
    }

    static bool isValidSegment(const string &str) {
        auto num = stoi(str);
        if(str[0] == '0' && str.size() > 1)
            return false;
        return num >= 0 && num <= 255;
    }
};

vector<string> validIPAddresses(string str) {
    // Time: O(1), Space: O(1)
    unordered_set<string> result;
    vector<string> segments;
    Solution::generate(0, segments, result, str);
    return vector<string>(result.begin(), result.end());
}


int main(){
    auto res = validIPAddresses("1921680");
    for(auto each: res)
        cout << each << endl;

    return 0;
}