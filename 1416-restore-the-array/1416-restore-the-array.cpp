class Solution {
private:
    vector<int> dp;
    int MOD = 1e9 + 7;
    int dpSolve(string &s, int k, int i){
        if(i == s.size())
            return 1;
        if(s[i] == '0')
            return 0;
        if(dp[i] != -1)
            return dp[i];
        
        long long num = 0;
        int ans = 0;
        
        for(int j = i; j<s.size(); j++){
            num = num * 10 + s[j] - '0';
            if(num>k)   break;
            ans += dpSolve(s, k, j + 1);
            ans %= MOD;
        }
        return dp[i] = ans;
    }
public:
    int numberOfArrays(string s, int k) {
        dp.resize(s.size(), -1);
        return dpSolve(s, k, 0);
    }
};