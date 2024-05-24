#include <iostream>

using namespace std;

long long  sum_digits(const string& str);

string superdigit(const string& str, long long  k=1){
    long long sum = k * sum_digits(str);
    if(sum < 10)
        return to_string(sum);

    return superdigit(to_string(sum));
}

long long  sum_digits(const string& str){
    long long  sum = 0;

    for(auto& num: str)
        sum += num - '0';

    return sum;
}

int main(){
    string str;
    int k;
    cin >> str >> k;

    cout << superdigit(str, k) << endl;

    return 0;
}