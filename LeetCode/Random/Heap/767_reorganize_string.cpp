struct Letter {
    char ch;
    int count;

    Letter(char ch = '$', int count = 0):ch(ch), count(count){}
};


struct Compare {
    bool operator()(const Letter& lhs, const Letter& rhs){
        return lhs.count < rhs.count;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        // Time: O(nlogn), Space: O(n)
        unordered_map<char, int> ft;
        for(auto letter: s)
            ft[letter]++;

        string result;
        priority_queue<Letter, std::vector<Letter>, Compare> pq;

        for(auto&[letter, cnt]: ft)
            pq.emplace(letter, cnt);

        while(pq.top().count != 0){
            auto first_top = pq.top(); pq.pop();
            Letter second_top;

            if(!pq.empty()){
                second_top = pq.top();
                pq.pop();
            }

            // if the string is empty or the last character is not the same as the top char, we can push it
            if(result.empty() || result.back() != first_top.ch){
                first_top.count--;
                result.push_back(first_top.ch);
                pq.push(first_top);
                pq.push(second_top);
                continue;
            }

            if(second_top.count == 0)
                return "";

            second_top.count--;
            result.push_back(second_top.ch);
            pq.push(second_top);
            pq.push(first_top);
        }

        return result.size() == s.size() ? result : "";
    }
};