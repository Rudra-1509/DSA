class MyQueue {
public:
    stack<int> st;
    MyQueue() {}
    
    void push(int x) {
        if(empty()){
            st.push(x);
            return;
        }
        int ele=pop();
        push(x);
        st.push(ele);

    }
    
    int pop() {
        if(empty()) return -1;
        int ele=st.top();
        st.pop();
        return ele;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
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