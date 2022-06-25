class Solution {
private:
    int globalMin = INT_MAX;
    vector<vector<int>> dp;

    int solve(vector<int>& coins, int amount, int n){
        if(amount == 0)
           return 0;
        if(n==0) return INT_MAX-1;
        
        if(dp[n][amount] != -1)
            return dp[n][amount];
        
        
        if(coins[n-1] <= amount)
            return dp[n][amount] = min(1 + solve(coins, amount - coins[n-1],n), 
                                       solve(coins, amount, n-1));
        else if(coins[n-1]>amount)
            return dp[n][amount] = solve(coins, amount, n-1);
        
        return dp[n][amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if(!amount) return 0;
        int n = coins.size();
        dp.resize(n+1, vector<int>(amount+1, -1));
        for(int i = 0; i < n+1; i++)
            dp[i][0] = 0;
        for(int j = 0; j < amount+1; j++)
            dp[0][j] = INT_MAX-1;
        
        for(int i = 1; i<n+1;i++){
            for(int j = 1; j<amount+1;j++){
                if(coins[i-1]<=j)
                    dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return (dp[n][amount] == INT_MAX - 1)?-1:dp[n][amount];
        
        
    }
};