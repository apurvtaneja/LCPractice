class Solution {
private:
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int sumOfArray = accumulate(nums.begin(),nums.end(),0);
        
        if(((sumOfArray - target) % 2 == 1) || (target > sumOfArray))
            return 0;
        
        // if the sum to find is negative. we cant initialize the array with a negative value;
        int sumToFind = abs((sumOfArray + target)/2);
        
        // if(sumToFind<0) sumToFind *= -1; 
        
        vector<vector<int>> dp(n+1, vector<int>(sumToFind+1));
        
        dp[0][0] = 1;
        
        for(int i = 1; i<n+1; i++){
            for(int j = 0; j<sumToFind+1; j++){
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sumToFind];
    }
};