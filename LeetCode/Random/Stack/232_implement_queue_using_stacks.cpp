class MyQueue {
    stack<int> pop_stack;
    stack<int> push_stack;

public:
    MyQueue() {

    }

    void push(int x) {
        push_stack.push(x);
    }

    int pop() {
        move_elements();
        auto result = pop_stack.top();
        pop_stack.pop();
        return result;
    }

    int peek() {
        move_elements();
        return pop_stack.top();
    }

    bool empty() {
        return pop_stack.empty() && push_stack.empty();
    }

    void move_elements(){
        if(pop_stack.empty())
            while(push_stack.size()){
                pop_stack.push(push_stack.top());
                push_stack.pop();
            }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */