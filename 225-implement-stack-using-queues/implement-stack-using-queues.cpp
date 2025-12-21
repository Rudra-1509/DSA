class MyStack {
    queue<int> q;
public:
    MyStack() {}
    
    void push(int x) {
        q.push(x);
        int size=q.size();
        for(int k=1;k<=size-1;k++){
            int ele=q.front();q.pop();
            q.push(ele);
        }
    }
    
    int pop() {
        if(empty()) return -1;
        int ele=q.front();
        q.pop();
        return ele;
    }
    
    int top() {
        if(empty())   return -1;
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */