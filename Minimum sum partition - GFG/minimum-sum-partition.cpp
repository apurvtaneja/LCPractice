// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int nums[], int n)  { 
	    int range = 0;
        for(int i=0; i<n; i++)    range+=nums[i];
        
        vector<vector<bool>> dp(n+1,vector<bool>(range+1, false));
        
        for(int i=0; i<n+1; i++)
            dp[i][0] = true;
        
        for(int i=1; i<n+1; i++){
            for(int j=0; j<range+1; j++){
                if(nums[i-1]<=j)
                    dp[i][j] = (dp[i-1][j-nums[i-1]] or dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        vector<int> s1Candidates;
        
        for(int i=0; i<=range/2; i++)
            if(dp[n][i]){
                s1Candidates.push_back(i);
                // cout<<i<<endl;
            }
        int minS = INT_MAX;
        for(int i: s1Candidates)
            minS = min(minS, abs(range-(2*i)));
        
        return minS;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends