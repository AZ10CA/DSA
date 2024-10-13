class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        // Time: O(n log n), Space: O(n), where n is the size of keyTime
        map<string, vector<string>> mp;
        for(int i = 0; i < keyName.size(); i++)
            mp[keyName[i]].push_back(keyTime[i]);


        vector<string> names;
        for(auto&[name, times]: mp){
            std::sort(times.begin(), times.end());
            if(times.size() < 3)
                continue;
            for(int i = 0; i < times.size() - 2; i++){
                if(is_in_hour(i, times)){
                    names.push_back(name);
                    break;
                }
            }
        }

        return names;
    }

    bool is_in_hour(int start_idx, const vector<string>& times){
        auto first = to_minutes(times[start_idx]);
        auto third = to_minutes(times[start_idx + 2]);
        return third - first <= 60;
    }

    long long to_minutes(string time){
        auto hour = stoi(time.substr(0, 2));
        auto minutes = stoi(time.substr(3, 2));
        return minutes + hour * 60;
    }
};