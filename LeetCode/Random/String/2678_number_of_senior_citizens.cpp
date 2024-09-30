class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for(auto& each: details){
            string age = each.substr(each.size() - 4, 2);
            cnt += stoi(age) > 60;
        }

        return cnt;
    }
};