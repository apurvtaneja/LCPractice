class Solution {
private:
    vector<vector<int>> dp;
    int dpSolve(int amount, vector<int>& coins, int n){
        if(n==0){
            if(amount==0)
                return 1;
            return 0;
        }
        if(dp[n][amount] != -1)
            return dp[n][amount];
        if(coins[n-1] <= amount)
            return dp[n][amount] = dpSolve(amount - coins[n-1], coins, n) + 
                                        dpSolve(amount, coins, n-1);
        else
            return dp[n][amount] = dpSolve(amount, coins, n-1);
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        // dp.resize(n+1, vector<int>(amount + 1, -1));
        // return dpSolve(amount, coins, n);
        
        dp.resize(n+1, vector<int>(amount + 1, 0));
        
        for(int i = 0; i<n+1; i++)
            dp[i][0] = 1;
        
        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<amount+1; j++){
                if(coins[i-1]<= j)
                    dp[i][j] = dp[i][j - coins[i-1]] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][amount];
    }
};