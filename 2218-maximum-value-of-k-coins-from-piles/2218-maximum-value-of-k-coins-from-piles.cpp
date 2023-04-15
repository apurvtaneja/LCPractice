class Solution {
private:
    vector<vector<int>> dp;
    
    int dpSolve(vector<vector<int>>& piles, int k, int n){
        if(n == 0 || k == 0)
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
        
        // dp.resize(n+1, vector<int>(k+1,-1));
        // int ans = dpSolve(piles, k, n);
        // return ans;
        
        dp.resize(n+1, vector<int>(k+1,0));
        
        for(int i = 1; i< n+1; i++){
            for(int j = 1; j<k+1; j++){
                int currentSum = 0;
                for(int coin = 0; coin<= min((int)piles[i-1].size(), j); coin++){
                    if(coin>0)
                        currentSum += piles[i-1][coin-1];
                    
                    dp[i][j] = max(dp[i][j], dp[i-1][j-coin] + currentSum);
                }
            }
        }
        
        return dp[n][k];
    }
};