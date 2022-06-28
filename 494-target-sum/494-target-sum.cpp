class Solution {
private:
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int sumOfArray = 0;
        for(int i : nums)   sumOfArray += i;
        
        if(((sumOfArray - target) % 2 == 1) || (target > sumOfArray))
            return 0;
        
        int sumToFind = (sumOfArray + target)/2;
        
        int sizeSumToFind = sumToFind;
        if(sumToFind < 0)
            sizeSumToFind = sumToFind * -1;
        vector<vector<int>> dp(n+1, vector<int>(sizeSumToFind+1));
        
        dp[0][0] = 1;
        
        for(int i = 1; i<n+1; i++){
            for(int j = 0; j<sizeSumToFind+1; j++){
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sizeSumToFind];
    }
};