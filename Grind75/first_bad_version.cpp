// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int answer = -1;
        // recursive_binary_search(1, n, answer);
        answer = iterative_binary_search(n);
        return answer;
    }

    void recursive_binary_search(int left, int right, int& answer){
        // Time: O(logn), Space: O(logn) due to recursion
        if(left > right)
            return;
        auto middle = left + (right - left) / 2;
        if(isBadVersion(middle)){
            answer = middle;
            return recursive_binary_search(left, middle - 1, answer);
        }
        recursive_binary_search(middle + 1, right, answer);
    }

    int iterative_binary_search(int n){
        int answer = -1;
        int left = 1, right = n;

        while(left <= right){
            int middle = left + (right - left) / 2;
            if(isBadVersion(middle)){
                answer = middle;
                right = middle - 1;
            } else left = middle + 1;
        }

        return answer;
    }
};