class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long int sum = 0;
        for(int i: nums)    sum+=i;
        
        if(sum%2!=0)    return false;
        
        int target = sum/2;
        int n = nums.size();
        
        vector<vector<bool>> dp(n+1, vector<bool>(target+1));
        
        for(int j = 0; j<target+1; j++)
            dp[0][j] = false;
        
        for(int i = 0; i<n+1; i++)
            dp[i][0] = true;
        
        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<target+1; j++){
                if(nums[i-1]<=j)
                    dp[i][j] = (dp[i-1][j-nums[i-1]] or dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][target];
    }
};