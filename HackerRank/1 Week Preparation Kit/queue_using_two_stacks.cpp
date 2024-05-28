#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class Queue {
    stack<int> push_stack;
    stack<int> pop_stack;

public:
    void enqueue(int element){
        push_stack.push(element);
    }

    void dequeue(){
        move_all();
        if(not pop_stack.empty())
            pop_stack.pop();
    }

    void print_last(){
        move_all();
        if(pop_stack.empty())
            return;
        cout << pop_stack.top() << endl;
    }

private:
    void move_all(){
        if(pop_stack.empty())
            while(!push_stack.empty()){
                pop_stack.push(push_stack.top());
                push_stack.pop();
            }
    }
};

int main() {
    int q;
    cin >> q;
    Queue queue;
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int x;
            cin >> x;
            queue.enqueue(x);
        } else if(t == 2){
            queue.dequeue();
        } else queue.print_last();
    }
    return 0;
}
