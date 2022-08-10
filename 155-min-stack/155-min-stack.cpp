class MinStack {
public:
    stack<int>ss; //supporting stack
    stack<int>s;
    MinStack() {
       
    }
    
    void push(int val) {
        s.push(val);
        if(ss.empty() or ss.top()>=val)
            ss.push(val);
        return;
    }
    
    void pop(){
        if(s.size()==0)
            return;
        int ans=s.top();
        s.pop();
        if(ans==ss.top())
            ss.pop();
        return;
    }
    
    int top(){
        if(s.size()==0)
            return -1;
        return s.top();
        
    }
    
    int getMin() {
        if(ss.size()==0)
            return -1;
        else
            return ss.top();
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