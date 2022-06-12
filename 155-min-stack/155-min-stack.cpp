class MinStack {
public:
    
    // stack will store a pair of {val, min. till now}
    
    stack<pair<int, int>> st;
    
    MinStack() {
        
    }
    
    void push(int val) {
        
        if(st.empty())
        {
            st.push({val, val});
        }
        else
        {
            int mini = min(val, st.top().second);
            
            st.push({val, mini});
        }
    }
    
    void pop() {
        
        st.pop();
    }
    
    int top() {
        
        return st.top().first;
    }
    
    int getMin() {
        
        return st.top().second;
    }
};