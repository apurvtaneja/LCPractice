// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
private:

    // int mod = 1000000007;
    // vector<vector<int>>dp;
    // int dpSolve(int arr[], int n, int sum){
    //     if(n==0){
    //         if(sum==0)
    //             return 1;
    //         return 0;
    //     }
    //     if(dp[n][sum]!=-1)
    //         return dp[n][sum];
            
    //     if(arr[n-1] <= sum)
    //         return dp[n][sum] = (dpSolve(arr,n-1,sum-arr[n-1])%mod + dpSolve(arr,n-1,sum)%mod)%mod;
    //     else if(arr[n-1]>sum)
    //         return dp[n][sum] = dpSolve(arr,n-1,sum)%mod;
            
    // }
public:
	int perfectSum(int arr[], int n, int sum)
	{
	    int mod = 1000000007;
	    int s=accumulate(arr,arr+n,0);
        if(s<sum)   return 0;
        vector<vector<int>>dp;
	    dp.resize(n+1, vector<int>(sum+1, 0));
	    
	    for(int i = 0; i<n+1; i++)
	        dp[i][0]=1;

        for(int i = 1; i<n+1; i++){
	        for(int j = 0; j<sum+1; j++){
	            if(arr[i-1] <= j)
	                dp[i][j] = (dp[i-1][j - arr[i-1]]%mod + dp[i-1][j]%mod)%mod;
	            else
	                dp[i][j] = dp[i-1][j]%mod;
	        }
        }
        
        return dp[n][sum];
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