#include <bits/stdc++.h>

using namespace std;



int main(){
    string time;
    cin >> time;

    auto hour = stoi(time.substr(0, 2));
    auto minute = time.substr(3, 2);
    auto second = time.substr(6, 2);
    auto is_am = time.substr(8, 2) == "AM";

    hour %= 12;
    if(not is_am)
        hour += 12;

    cout << setw(2) << setfill('0') << hour << ":" << minute << ":" << second << endl;

    return 0;
}
