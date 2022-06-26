class Solution {
private:
    vector<vector<int>> dp;
    int countSubsetSum(vector<int>& nums, int target, int n){
        if(n==0){
            if(target == 0)
                return 1;
            return 0;
        }
        
        if(dp[n][target] != -1)
            return dp[n][target];
        
        if(nums[n-1]<=target)
            return dp[n][target] = countSubsetSum(nums, target - nums[n-1], n-1) + 
                                    countSubsetSum(nums, target, n-1);
        else
            return dp[n][target] = countSubsetSum(nums, target, n-1);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int sumOfArray = 0;
        for(int i : nums)   sumOfArray += i;
        
        if(((sumOfArray - target) % 2 == 1) || (target > sumOfArray))
            return 0;
        
        int sumToFind = (sumOfArray - target)/2;
        
        dp.resize(n+1, vector<int>(sumToFind+1));
        
        // return (target > sumOfArray) ? 0: countSubsetSum(nums, sumToFind, n);
        
 
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