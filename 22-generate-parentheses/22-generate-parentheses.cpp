class Solution {
private:
    void backtrack(int n, int open, int close, vector<string> &ans,  string t){
        if(t.size() == 2 * n){
            ans.push_back(t);
            return; 
        }
        if(open < n){
            t.push_back('(');
            backtrack(n, open + 1, close, ans, t);
            t.pop_back();
        }
        if(open > close){
            t.push_back(')');
            backtrack(n, open, close + 1, ans, t);
            t.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(n, 0, 0, ans, "");
        return ans;
    }
};