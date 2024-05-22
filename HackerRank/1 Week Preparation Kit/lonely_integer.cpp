#include <iostream>

using namespace std;


int main(){
    int t;
    cin >> t;

    auto lonely = 0;
    while(t--){
        int num;
        cin >> num;
        lonely = lonely xor num;
    }

    cout << lonely << endl;

    return 0;
}