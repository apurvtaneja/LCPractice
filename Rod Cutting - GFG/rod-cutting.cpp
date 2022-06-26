// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
private:
    vector<vector<int>> dp;
    
    int dpSolve(int price[], vector<int>& lengths, int l, int n){
        if(n==0 || l==0)
            return 0;
            
        if(dp[n][l]!=-1)
            return dp[n][l];
            
        if(lengths[n-1]<=l)
            return dp[n][l] = max(price[n-1] + dpSolve(price,lengths,l - lengths[n-1], n),
                                dpSolve(price,lengths, l, n-1));
    
        else
            return dp[n][l] = dpSolve(price,lengths, l, n-1);
    }
public:
    int cutRod(int price[], int n) {
        
        vector<int> lengths;
        
        for(int i=1;i<n+1;i++)
            lengths.push_back(i);
            
        dp.resize(n+1, vector<int>(n+1, -1));
        
        return dpSolve(price,lengths,n, n);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends