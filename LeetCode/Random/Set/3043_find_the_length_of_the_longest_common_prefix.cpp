class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // Time: O(nlogk + mlogk), Space: O(nlogk), where k: the largest number allowed in the input
        cin.tie(nullptr);
        cout.tie(nullptr);
        std::ios::sync_with_stdio(false);

        int max_length = 0;
        unordered_set<int> prefixes;

        for(auto& each: arr1){
            while(each != 0){
                prefixes.insert(each);
                each /= 10;
            }
        }

        for(auto& each: arr2)
            while(each != 0){
                if(prefixes.find(each) != prefixes.end())
                    max_length = std::max((int)log10(each) + 1, max_length);
                each /= 10;
            }


        return max_length;
    }
};