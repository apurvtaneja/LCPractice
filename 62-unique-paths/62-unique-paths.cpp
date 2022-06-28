class Solution {
private:
    vector<vector<int>> dp;
    int dpSolve(int m, int n, int i, int j){
        if(i<0 || j<0 || i>=m || j>=n)
            return 0;
        if(m-1==i && n-1==j)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j] = dpSolve(m,n,i+1,j) + dpSolve(m, n, i, j+1);
    }
public:
    int uniquePaths(int m, int n) {
        dp.resize(m+1,vector<int>(n+1, -1));
        // return dpSolve(m,n,0,0);
        for(int i=0; i<m; i++)
            dp[i][n-1] = 1;
        for(int i=0; i<n; i++)
            dp[m-1][i] = 1;
        
        for(int i=m-2; i>=0;i--)
            for(int j=n-2; j>=0; j--)
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
        
        return dp[0][0];
    }
};