class Solution {
private:
    vector<vector<int>> dp;
    
    int dpSolve(vector<vector<int>>& piles, int k, int n){
        if(n == 0)
            return 0;
        if(dp[n][k] != -1)
            return dp[n][k];
        
        int currentSum = 0;
        for(int i = 0; i<= min((int)piles[n-1].size(), k); i++){
            if(i>0)
                currentSum += piles[n-1][i-1];
            dp[n][k] = max(dp[n][k], dpSolve(piles, k - i, n-1) + currentSum);
        }
        return dp[n][k];
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        
        dp.resize(n+1, vector<int>(k+1,-1));
        
        int ans = dpSolve(piles, k, n);
        return ans;
    }
};