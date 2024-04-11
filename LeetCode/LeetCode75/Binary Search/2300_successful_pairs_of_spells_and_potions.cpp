class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // Time: O(nlogn), Space: O(n)
        vector<int> result;
        std::sort(potions.begin(), potions.end());

        for(auto spell: spells){
            long long min_potion = std::ceil((double)success / spell);
            int idx = std::lower_bound(potions.begin(), potions.end(), min_potion) - potions.begin();
            int successful_combos = potions.size() - idx;
            result.push_back(successful_combos);
        }

        return result;
    }
};