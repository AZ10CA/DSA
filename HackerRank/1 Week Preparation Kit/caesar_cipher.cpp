#include <iostream>

using namespace std;

void encrypt(string& str, int k){
    for(auto& letter: str){
        if(letter >= 'a' && letter <= 'z'){
            auto initial_idx = letter - 'a';
            auto final_idx = (initial_idx + k) % 26;
            letter = final_idx + 'a';
        }
        else if(letter >= 'A' && letter <= 'Z'){
            auto initial_idx = letter - 'A';
            auto final_idx = (initial_idx + k) % 26;
            letter = final_idx + 'A';
        }
    }
}

int main(){
    int n, k;
    string s;

    cin >> n >> s >> k;

    encrypt(s, k);

    cout << s << endl;

    return 0;
}