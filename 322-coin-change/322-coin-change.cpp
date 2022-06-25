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
        dp.resize(coins.size()+1, vector<int>(amount+1, -1));
        int ans = solve(coins, amount, coins.size());
        return (ans == INT_MAX-1)?-1:ans;
    }
};