class Solution {
public:
    int majorityElement(vector<int> &nums) {
        // Time: O(n), Space: O(1)
        int majority, count = 0;
        for (auto num: nums) {
            if (count == 0) {
                majority = num;
                count = 1;
            } else if (majority == num)
                count++;
            else
                count--;

        }
        return majority;
    }
};