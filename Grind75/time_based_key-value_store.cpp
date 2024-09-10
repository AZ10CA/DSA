struct Data {
    string value;
    int time;

    Data(string value, int time):value(value), time(time){}
};

class TimeMap {
    unordered_map<string, vector<Data>> map;
public:
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        // Time: O(1)
        map[key].push_back(Data(value, timestamp));
    }

    string get(string key, int timestamp) {
        // Time: O(logn)

        // Binary Search - Find the rightmost element that is less than equal to "timestamp"
        auto& arr = map[key];
        int answer = -1;
        int left = 0, right = arr.size() - 1;
        while(left <= right){
            int middle = left + (right - left) / 2;
            if(arr[middle].time == timestamp)
                return arr[middle].value;
            if(arr[middle].time < timestamp){
                answer = middle;
                left = middle + 1;
            } else
                right = middle - 1;
        }

        return answer == -1 ? "" : arr[answer].value;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */