class Solution {
private:
    vector<int> dp;
    int helper(int n){
        if(n == 0 || n == 1)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = helper(n-1) + helper(n-2);
    }
public:
    int climbStairs(int n) {
        dp.resize(n+1, -1);
        return helper(n);
    }
};