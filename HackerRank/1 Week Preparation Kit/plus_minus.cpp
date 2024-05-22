#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    double p = 0, z = 0, n = 0;

    for(int i = 0; i < t; i++){
        double num;
        cin >> num;
        if(num > 0)
            p++;
        else if(num < 0)
            n++;
        else
            z++;
    }

    cout << p / t << endl << n / t << endl << z / t << endl;
    return 0;
}
