class Solution {
private:
    vector<vector<int>> dp;
    int dpSolve(string s1, string s2, int i, int j){
        if(i == 0 || j == 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i-1] == s2[j-1])
            return dp[i][j] = 1 + dpSolve(s1,s2, i-1, j-1);
        else
            return dp[i][j] = max(dpSolve(s1,s2, i-1, j),dpSolve(s1,s2, i, j-1));
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;
        
        // dp.resize(n+1, vector<int>(n+1,-1));
        // return dpSolve(s1, s2, n, n);
        dp.resize(n+1, vector<int>(n+1,0));
        
        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<n+1; j++){
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n][n];
        
    }
};