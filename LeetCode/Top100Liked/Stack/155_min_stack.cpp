class MinStack {
    stack<int> main;
    stack<int> min_values;
public:
    // Time: O(1), Space: O(n)
    MinStack() {

    }

    void push(int val) {
        main.push(val);
        if(min_values.empty() || val <= min_values.top())
            min_values.push(val);
    }

    void pop() {
        if(main.top() == min_values.top())
            min_values.pop();
        main.pop();
    }

    int top() {
        return main.top();
    }

    int getMin() {
        return min_values.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */