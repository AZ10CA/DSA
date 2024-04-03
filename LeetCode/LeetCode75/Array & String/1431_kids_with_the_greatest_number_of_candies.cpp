class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // Time: O(n), Space: O(n)
        auto max_candies = 0;
        for(auto candy: candies)
            max_candies = std::max(max_candies, candy);

        vector<bool> result(candies.size());
        for(int i = 0; i < candies.size(); i++)
            if(candies[i] + extraCandies >= max_candies)
                result[i] = true;

        return result;
    }
};