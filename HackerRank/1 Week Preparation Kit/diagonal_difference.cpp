#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    auto diff = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            int num;
            cin >> num;
            if(i == j)
                diff += num;
            if(i + j == n - 1)
                diff -= num;
        }

    cout << std::abs(diff) << endl;

    return 0;
}