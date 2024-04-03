class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Time: O(n + m), Space: O(n + m)
        if(str1 + str2 != str2 + str1)
            return "";
        auto str_gcd = std::gcd(str1.size(), str2.size());
        return str1.substr(0, str_gcd);
    }
};