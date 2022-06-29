class Solution {
    double solve(double x, int n){
        if(x == 0)  return 0;
        if(n == 0)  return 1;
        
        double res = solve(x, n/2);
        
        res = res * res;
        
        return n&1? x * res: res;
    }
public:
    double myPow(double x, int n) {
        double ans = solve(x, abs(n));
        
        return n>=0? ans: 1/ans;
    }
};