class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // Time: O(nlogn), Space: O(n)
        int placement = 1;
        map<int, int> score_idx;
        vector<string> result(score.size());

        for(int i = 0; i < score.size(); i++)
            score_idx[-score[i]] = i;


        for(auto&[score, idx]: score_idx)
            result[idx] = get_rank(placement++);


        return result;
    }

    string get_rank(int placement){
        string ranks[3] = {"Gold", "Silver", "Bronze"};
        if(placement - 1 < 3)
            return ranks[placement - 1] + " Medal";

        return to_string(placement);
    }
};