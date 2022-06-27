// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
private:
    vector<vector<int>> dp;
    int maxSubStr = INT_MIN;
    
    int dpSolve(string s1, string s2, int m, int n){
        if(m == 0 || n == 0)
            return 0;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        if(s1[m-1]==s2[n-1])
            dp[m][n] = 1 + dpSolve(s1, s2, m - 1, n-1);
        else
            dp[m][n] = 0;
        
        dpSolve(s1, s2, m - 1, n);
        dpSolve(s1, s2, m, n-1);
        
        maxSubStr = max(maxSubStr,dp[m][n]);
        return dp[m][n];
    }
public:

    int longestCommonSubstr (string s1, string s2, int m, int n)
    {
        // dp.resize(m+1,vector<int>(n+1,-1));
        // dpSolve(S1, S2, m, n);
        
        // return maxSubStr;
        
        dp.resize(m+1,vector<int>(n+1,0));
        
        for(int i = 1; i<m+1; i++){
            for(int j = 1; j<n+1; j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    maxSubStr = max(maxSubStr,dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }
        return maxSubStr==INT_MIN?0:maxSubStr;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends