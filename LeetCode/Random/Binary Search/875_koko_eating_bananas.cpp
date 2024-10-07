class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Time: O(nlogm), Space: O(1), where m: max pile
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int left = 1, right = *std::max_element(piles.begin(), piles.end());
        int answer = -1;

        while(left <= right){
            int middle = left + (right - left) / 2;
            auto result = simulate(middle, h, piles);
            if(result <= h){
                answer = middle;
                right = middle - 1;
            } else
                left = middle + 1;
        }

        return answer;
    }

    int simulate(int k, int h, const vector<int>& piles){
        int hours_sum = 0;
        for(auto bananas: piles){
            hours_sum += bananas / k;
            hours_sum += (bananas % k) > 0;
            if(hours_sum > h)
                break;
        }

        return hours_sum;
    }
};