class Solution {
private:
    vector<int> dp;
    int dpSolve(string s, int n){
        int len = s.length();
        if(n==len)
            return 1;
        if(n>len || s[n]=='0')
            return 0;
        
        if(dp[n]!=-1)
            return dp[n];
        
        int oneDigit = 0, twoDigit = 0;
        if(s[n] != '0')
            oneDigit = dpSolve(s, n+1);
        
        // Ensuring that 2 digit number is less than 26. if so, only then make the call.
        if(n+1 < len && s[n] == '1' || (s[n] == '2' && s[n+1] <= '6')) 
            twoDigit = dpSolve(s, n+2); 
        
        return dp[n] = oneDigit + twoDigit;
    }
public:
    int numDecodings(string s) {
        int n = s.length();
        if(n<1) return 0;
        // if(n==1 && s[0]!='0') return 1;
        dp.resize(n+1,-1);
        return dpSolve(s,0);
    }
};