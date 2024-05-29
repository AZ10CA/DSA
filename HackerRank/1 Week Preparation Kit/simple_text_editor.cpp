#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


class Operation {
    int type;
    string data;
    int size;

public:
    Operation(int type, string data = "", int size = 0): type(type), data(data), size(size){}

    void undo(string& str){
        if(type == 1){
            str = str.substr(0, str.size() - size);
        } else if(type == 2){
            str += data;
        } else {
            cout << "UNKNOWN OPERATION" << endl;
        }
    }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string text;
    stack<Operation> operations;

    int q;
    cin >> q;

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            string data;
            cin >> data;
            text += data;
            operations.emplace(type, "", data.size());
        } else if(type == 2){
            int k;
            cin >> k;
            auto size = text.size();
            operations.emplace(type, text.substr(size - k, k), 0);
            text = text.substr(0, text.size() - k);
        } else if(type == 3){
            int k;
            cin >> k;
            cout << text[k - 1] << endl;
        } else {
            operations.top().undo(text);
            operations.pop();
        }
    }

    return 0;
}
