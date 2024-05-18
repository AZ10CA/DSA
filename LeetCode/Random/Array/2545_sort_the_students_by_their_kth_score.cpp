class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        // Time: O(nlogn), Space: O(1)
        std::sort(score.begin(), score.end(), [&](const vector<int>& first, const vector<int>& second){
            return first[k] > second[k];
        });

        return score;
    }
};