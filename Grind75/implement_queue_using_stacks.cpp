class MyQueue {
    stack<int> push_st;
    stack<int> pop_st;
public:
    MyQueue() {

    }

    void push(int x) {
        push_st.push(x);
    }

    int pop() {
        balance();
        if(!pop_st.empty()){
            auto top = pop_st.top();
            pop_st.pop();
            return top;
        }
        return -1;
    }

    int peek() {
        balance();
        if(!pop_st.empty())
            return pop_st.top();

        return -1;
    }

    bool empty() {
        return pop_st.empty() && push_st.empty();
    }

    void balance(){
        if(pop_st.empty())
            while(!push_st.empty()){
                auto top = push_st.top();
                push_st.pop();
                pop_st.push(top);
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