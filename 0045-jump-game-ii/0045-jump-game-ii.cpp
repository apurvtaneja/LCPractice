class Solution {
private:
    vector<int> dp;
    int dpSolve(vector<int>& nums, int i){
        if(i >= nums.size()-1)
            return 0;
        if(dp[i] != INT_MAX - 1)
            return dp[i];
        
        for(int j = 1; j<=nums[i]; j++)
            dp[i] = min(dp[i], 1 + dpSolve(nums, i + j));
        
        return dp[i];
    }
public:
    int jump(vector<int>& nums) {
        dp.resize(nums.size(), INT_MAX-1);
        return dpSolve(nums,0);
    }
};