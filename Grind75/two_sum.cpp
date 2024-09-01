class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        return solution_3(nums, target);
    }

    vector<int> solution_1(const vector<int>& nums, int target){
        // Time: O(n^2), Space: O(1)
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {};
    }

    vector<int> solution_2(const vector<int>& nums, int target){
        // Time: O(nlogn), Space: O(n)
        // store the index with the number in a new array
        vector<pair<int, int>> indexed;
        for(int i = 0; i < nums.size(); i++)
            indexed.emplace_back(nums[i], i);

        // sort the pairs, based on the value of num in ascending order
        std::sort(indexed.begin(), indexed.end(), [](auto& first, auto& second){
            if(first.first == second.first)
                return first.second < second.first;

            return first.first < second.first;
        });

        // use two pointers to make target
        int left = 0, right = nums.size() - 1;
        while(left < right){
            auto sum = indexed[left].first + indexed[right].first;
            if(sum == target)
                return {indexed[left].second, indexed[right].second};
            if(sum > target)
                right--;
            else
                left++;
        }

        return {};
    }

    vector<int> solution_3(const vector<int>& nums, int target){
        // Time: O(n), Space: O(n)
        unordered_map<int, int> table;
        for(int i = 0; i < nums.size(); i++){
            if(table.find(target - nums[i]) != table.end())
                return {i, table[target - nums[i]]};
            table[nums[i]] = i;
        }

        return {};
    }
};