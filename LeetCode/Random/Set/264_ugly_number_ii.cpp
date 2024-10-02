class Solution {
public:
    Solution(){
        cin.tie(nullptr);
        cout.tie(nullptr);
        std::ios::sync_with_stdio(false);
    }
public:
    int nthUglyNumber(int n) {
        set<long long> to_visit;

        to_visit.insert(1);

        while(!to_visit.empty()){
            auto top = *to_visit.begin();
            to_visit.erase(top);
            n--;

            if(n == 0)
                return top;

            to_visit.insert(top * 2);
            to_visit.insert(top * 3);
            to_visit.insert(top * 5);
        }


        return -1;
    }
};
