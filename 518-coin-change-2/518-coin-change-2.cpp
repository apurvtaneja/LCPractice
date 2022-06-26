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
        dp.resize(n+1, vector<int>(amount + 1, -1));
        return dpSolve(amount, coins, n);
    }
};