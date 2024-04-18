class Solution {
public:
    int hIndex(vector<int>& citations) {
        // Time: O(nlogn), Space: O(1)
        std::sort(citations.begin(), citations.end());

        int left = 0, right = citations.size() - 1;
        int answer = 0;

        while(left <= right){
            auto middle = left + (right - left) / 2;
            if(citations.size() - middle <= citations[middle]){
                answer = std::max(answer, (int)citations.size() - middle);
                right = middle - 1;
            } else left = middle + 1;
        }

        return answer;
    }
};