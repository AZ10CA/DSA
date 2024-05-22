#include <iostream>
#include <vector>

using namespace std;


int main(){
    int t;
    cin >> t;

    vector<int> ft(100, 0);

    while(t--){
        int num;
        cin >> num;
        ft[num]++;
    }

    for(auto num: ft)
        cout << num << " ";

    return 0;
}