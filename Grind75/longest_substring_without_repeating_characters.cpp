class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Time: O(n), Space: O(m), where m is the count of unique characters in s
        int left = 0, answer = 0;
        unordered_set<char> seen;

        for(int right = 0; right < s.size(); right++){
            auto& ch = s[right];
            if(seen.find(ch) == seen.end()){
                answer = std::max(answer, right - left + 1);
                seen.insert(ch);
                continue;
            }

            while(seen.find(ch) != seen.end())
                seen.erase(s[left++]);

            seen.insert(ch);
        }

        return answer;
    }
};