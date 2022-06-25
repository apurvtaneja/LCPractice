// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    private:
        vector<vector<int>> dp;
        int dpSolve(int w, int wt[], int val[], int n){
            if(w==0 || n == 0)
                return 0;
                
            if(dp[n][w] != -1)
                return dp[n][w];
            
            if(wt[n-1] <= w)
                return dp[n][w] = max(val[n-1] + dpSolve(w - wt[n-1], wt, val, n-1), dpSolve(w,wt,val,n-1));
            else if(wt[n-1] > w)
                return dp[n][w] = dpSolve(w,wt,val,n-1);
        }
    public:
        //Function to return max value that can be put in knapsack of capacity W.
    
        int knapSack(int w, int wt[], int val[], int n) 
        { 
            dp.resize(n+1, vector<int>(w+1, -1));
            return dpSolve(w, wt, val, n);
        }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends