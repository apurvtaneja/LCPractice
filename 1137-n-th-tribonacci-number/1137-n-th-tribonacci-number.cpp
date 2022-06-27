class Solution {
private:
    vector<int> dp;
    
    int dpTri(int n){
        if(n == 0)  return dp[n] = 0;
        if(n == 1 || n == 2) return dp[n] = 1;
        if(dp[n]!=-1)   return dp[n];
        
        return dp[n] = dpTri(n - 1) + dpTri(n - 2) + dpTri(n - 3);
    }
public:
    int tribonacci(int n) {
        dp.resize(n+1,-1);
        return dpTri(n); 
    }
};