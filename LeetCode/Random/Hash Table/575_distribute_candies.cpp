class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        // Time: O(n), Space: O(n)
        unordered_map<int, int> types;
        for(auto candy: candyType)
            types[candy]++;

        return std::min((int)candyType.size() >> 1, (int)types.size());
    }
};