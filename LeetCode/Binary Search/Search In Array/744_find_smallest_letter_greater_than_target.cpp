class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // Time: O(logn), Space: O(1)
        auto ptr = std::upper_bound(letters.begin(), letters.end(), target);

        if(ptr == letters.end())
            return letters[0];

        return *ptr;
    }
};