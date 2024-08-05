
class Solution {
public:
    bool canCross(vector<int> &stones) {
        // Time: O(n^2), Space: O(n^2)
        vector<vector<int>> table(stones.size(), vector<int>(stones.size(), -1));
        return jump(0, 0, table, stones);
    }

    bool jump(int idx, int last_jump, vector<vector<int>> &table, const vector<int> &stones) {
        if (idx == stones.size() - 1)
            return true;

        auto &memo = table[idx][last_jump];
        if (memo != -1)
            return memo;

        auto can_jump = false;
        for (int i = idx + 1; i < stones.size(); i++) {
            int distance = stones[i] - stones[idx];
            if (distance > last_jump + 1)
                break;
            if(distance < last_jump - 1)
                continue;

            for (int j = -1; j <= 1; j++) {
                int next_jump = last_jump + j;
                if (next_jump + stones[idx] == stones[i])
                    can_jump |= jump(i, next_jump, table, stones);
            }
        }

        return memo = can_jump;
    }
};
