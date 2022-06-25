// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
private:

    int mod = 1000000007;
    vector<vector<int>>dp;
    int dpSolve(int arr[], int n, int sum){
        if(n==0){
            if(sum==0)
                return 1;
            return 0;
        }
        if(dp[n][sum]!=-1)
            return dp[n][sum];
            
        if(arr[n-1] <= sum)
            return dp[n][sum] = (dpSolve(arr,n-1,sum-arr[n-1])%mod + dpSolve(arr,n-1,sum)%mod)%mod;
        else if(arr[n-1]>sum)
            return dp[n][sum] = dpSolve(arr,n-1,sum)%mod;
            
    }
public:
	int perfectSum(int arr[], int n, int sum)
	{
	    
	    dp.resize(n+1, vector<int>(sum+1,-1));
	    return (dpSolve(arr,n,sum));
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends