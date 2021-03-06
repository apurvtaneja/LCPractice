class Solution {
private:
    vector<int> dp;
    int dpSolve(vector<int>& nums, int n){
        if(n<=0)    return 0;
        if(dp[n] != -1)
                return dp[n];
        return dp[n] = max(nums[n-1] + dpSolve(nums, n-2),dpSolve(nums, n-1));
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        dp.resize(n+1, -1);
        
        return dpSolve(nums, n);
    }
};