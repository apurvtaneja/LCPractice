class MinStack {
public:
    vector<int> s;
    int minEl = INT_MAX;
    
    MinStack() {
        
    }
    
    void push(int val) {
        minEl = min(val, minEl);
        s.push_back(val);
    }
    
    void pop() {
        // if(s.top() == minEl)
        s.pop_back();
        minEl = INT_MAX;
        for(int i:s)    minEl = min(i,minEl);
    }
    
    int top() {
        return s[s.size()-1];
    }
    
    int getMin() {
        return minEl;
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