class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int i = 0;
        int j = 0;
        
        stack<int> st;
        int n = pushed.size();
        
        while(i < n && j < n){
            st.push(pushed[i++]);
            while(!st.empty() && j<n && st.top() == popped[j])
                st.pop(), j++;
        }
        return j == n;
    }
};