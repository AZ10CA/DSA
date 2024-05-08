// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // Time: O(logn), Space: O(1)
        int answer = 0;
        int left = 1, right = n;
        while(left <= right){
            auto middle = left + (right - left) / 2;
            if(isBadVersion(middle)){
                answer = middle;
                right = middle - 1;
            } else
                left = middle + 1;
        }

        return answer;
    }
};