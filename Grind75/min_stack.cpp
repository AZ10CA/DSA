struct Node {
    int value;
    int min_value;

    Node(int value, int min_value):value(value), min_value(min_value){}
};

class MinStack {
    stack<Node> st;

public:
    MinStack() {

    }

    void push(int val) {
        if(st.empty()){
            st.push(Node(val, val));
            return;
        }

        auto new_node = Node(val, std::min(st.top().min_value, val));
        st.push(new_node);
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().value;
    }

    int getMin() {
        return st.top().min_value;
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