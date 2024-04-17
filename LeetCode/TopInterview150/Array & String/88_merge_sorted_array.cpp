class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Time: O(n + m), Space: O(1)
        int fp = m - 1, sp = n - 1;
        int idx = m + n - 1;

        while(fp >= 0 && sp >= 0){
            auto& first = nums1[fp], &second = nums2[sp];
            if(first > second){
                nums1[idx] = first;
                idx--;
                fp--;
            } else {
                nums1[idx] = second;
                idx--;
                sp--;
            }
        }

        while(fp >= 0)
            nums1[idx--] = nums1[fp--];

        while(sp >= 0)
            nums1[idx--] = nums2[sp--];
    }
};