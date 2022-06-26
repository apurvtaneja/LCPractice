class Solution {
private:
    vector<int> dp;
    int dpFib(int n){
        if(n == 0 || n == 1)    return n;
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = dpFib(n-1) + dpFib(n-2);
    }
public:
    int fib(int n) {
        dp.resize(n+1, -1);
        return dpFib(n);
    }
};