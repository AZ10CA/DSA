class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Time: O(n), Space: O(1)
        int fp = 0, sp = numbers.size() - 1;
        while(fp < sp){
            auto sum = numbers[fp] + numbers[sp];
            if(sum > target)
                sp--;
            else if(sum < target)
                fp++;
            else return {fp + 1, sp + 1};
        }

        return {};
    }
};