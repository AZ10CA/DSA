class Solution {
public:
    vector<int> minOperations(string boxes) {
        // Time: O(n), Space: O(n)
        vector<int> prefix(boxes.size(), 0), postfix(boxes.size(), 0);
        vector<int> result;
        int increment = 0;

        for(int i = 0; i < boxes.size(); i++){
            auto left = i > 0 ? prefix[i - 1] : 0;
            prefix[i] = left + increment;
            increment += boxes[i] - '0';
        }

        increment = 0;
        for(int i = boxes.size() - 1; i >= 0; i--){
            auto right = i < boxes.size() - 1 ? postfix[i + 1] : 0;
            postfix[i] = right + increment;
            increment += boxes[i] - '0';
        }

        for(int i = 0; i < boxes.size(); i++)
            result.push_back(prefix[i] + postfix[i]);

        return result;
    }
};

