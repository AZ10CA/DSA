class Solution {
public:
    vector<int> lexicalOrder(int n) {
        // Time: O(n), Space: O(logn)
        int number;
        vector<int> result;

        for(int i = 1; i < 10; i++){
            number = i;
            dfs(number, n, result);
        }

        return result;
    }

    void dfs(int& current_number, int max_number, vector<int>& result){
        if(current_number > max_number)
            return;

        result.push_back(current_number);

        for(int i = 0; i < 10; i++){
            current_number = current_number * 10 + i;
            if(current_number <= max_number)
                dfs(current_number, max_number, result);
            current_number /= 10;
        }
    }
};