class Solution {
    struct vector_hash {
        std::size_t operator()(const std::vector<int>& vec) const {
            std::size_t seed = 0;
            for (int i : vec) {
                seed ^= std::hash<int>{}(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Time: O(n^2), Space: O(n)
        std::sort(nums.begin(), nums.end());
        unordered_set<vector<int>, vector_hash> triplets;
        vector<vector<int>> result;

        for(int i = 0; i < nums.size() - 2; i++){
            int fp = i + 1;
            int sp = nums.size() - 1;
            auto target = 0 - nums[i];
            while(fp < sp){
                auto sum = nums[fp] + nums[sp];
                if(sum == target){
                    vector<int> triplet = {nums[i], nums[fp++], nums[sp--]};
                    std::sort(triplet.begin(), triplet.end());
                    if(triplets.find(triplet) == triplets.end()){
                        triplets.insert(triplet);
                        result.push_back(triplet);
                    }
                } else if(sum < target)
                    fp++;
                else
                    sp--;
            }
        }

        return result;
    }
};