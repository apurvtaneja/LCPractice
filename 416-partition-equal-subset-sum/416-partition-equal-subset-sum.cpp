class Solution {
private:
    vector<vector<int>> dp;
    
    bool dpSolve(vector<int>& nums, int target, int n){
        if(n == 0)
            return 0;
        if(target == 0)
            return 1;
        
        if(dp[n][target] != -1)
            return dp[n][target];
        
        if(nums[n-1]<=target)
            return dp[n][target] = dpSolve(nums,target-nums[n-1],n-1) or 
                                    dpSolve(nums, target,n-1);
        else if(nums[n-1]>target)
            return dp[n][target] = dpSolve(nums, target,n-1);
        
        return dp[n][target];
    }
    
public:
    bool canPartition(vector<int>& nums) {
        long int sum = 0;
        for(int i: nums)    sum+=i;
        
        if(sum%2!=0)    return false;
        
        int target = sum/2;
        int n = nums.size();
        
        dp.resize(n+1, vector<int>(target+1, -1));
        
        return dpSolve(nums, target, n);
    }
};