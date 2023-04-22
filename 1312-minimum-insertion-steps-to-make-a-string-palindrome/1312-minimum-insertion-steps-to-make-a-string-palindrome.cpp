class Solution {
private:
    vector<vector<int>> dp;
    int dpSolve(string &s1, string &s2, int i, int j){
        if(i == 0 || j == 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i-1] == s2[j-1])
            dp[i][j] = 1 + dpSolve(s1, s2, i -1, j - 1);
        else
            dp[i][j] = max(dpSolve(s1, s2, i, j - 1), dpSolve(s1, s2, i -1, j));
        
        return dp[i][j];
    }
public:
    int minInsertions(string s) {
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;
        
        int n = s.length();
         
        dp.resize(n+1, vector<int>(n+1, -1));
        
        int lcs = dpSolve(s1, s2, n, n);
        
        cout << lcs;
        
        return n - lcs;
    }
};