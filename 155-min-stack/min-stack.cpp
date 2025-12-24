class MinStack {
public:
    stack<long long>  st;
    int mini;
    MinStack() {
        mini=LLONG_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            mini=val;
            st.push(val);
            return;
        }
        if(val<mini){
            st.push(2LL*val-mini);
            mini=val;
        }
        else    st.push(val);
    }
    
    void pop() {
        if(st.empty())  return;
        if(st.top()>=mini){
            st.pop();
        }
        else{
            mini=2LL*mini-st.top();
            st.pop();
        }
        
    }
    
    int top() {
        if(st.empty())  return -9999;
        if(st.top()>=mini)  return st.top();
        else    return mini;
    }
    
    int getMin() {
        if(st.empty())     return -9999;
        return mini;
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