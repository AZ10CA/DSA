struct Pair {
    string word;
    int frequency;

    struct Comparator {
        bool operator()(const Pair& left, const Pair& right){
            if(left.frequency == right.frequency)
                return is_smaller(left.word, right.word);

            return left.frequency > right.frequency;
        }

        bool is_smaller(const string& left, const string& right){
            for(int i = 0; i < left.size(); i++)
                if(left[i] < right[i])
                    return true;
                else if(left[i] > right[i])
                    return false;

            return left.size() < right.size();
        }
    };
};


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // Time: O(nmlogk), Space: O(nm), where n: words.size(), m: average length of words
        unordered_map<string, int> ft;
        for(auto word: words)
            ft[word]++;


        priority_queue<Pair, vector<Pair>, Pair::Comparator> pq;
        for(const auto&[word, frequency]: ft){
            if(pq.size() != k)
                pq.push(Pair(word, frequency));
            else {
                auto top = pq.top();
                if(top.frequency < frequency || (top.frequency == frequency && word < top.word)){
                    pq.pop();
                    pq.push(Pair(word, frequency));
                }
            }
        }

        vector<string> result;
        while(!pq.empty()){
            result.push_back(pq.top().word);
            pq.pop();
        }

        std::reverse(result.begin(), result.end());
        return result;

    }
};