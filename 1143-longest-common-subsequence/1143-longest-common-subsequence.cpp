class Solution {
private:
    vector<vector<int>> dp;
    int dpSolve(string text1, string text2, int m, int n){
        if(m == 0 || n == 0)
            return 0;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        if(text1[m-1]==text2[n-1])
            return dp[m][n] = 1 + dpSolve(text1, text2, m - 1, n-1);
        else
            return dp[m][n] = max(dpSolve(text1, text2, m-1, n), 
                                  dpSolve(text1, text2, m, n-1));
        
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        // dp.resize(m+1,vector<int>(n+1,-1));
        // return dpSolve(text1, text2, m, n);
        dp.resize(m+1,vector<int>(n+1,0));

        for(int i = 1; i<m+1; i++){
            for(int j = 1; j<n+1; j++){
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);

            }
        }
        return dp[m][n];
        
    }
};