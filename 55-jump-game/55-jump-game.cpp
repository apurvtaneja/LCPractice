class Solution {
private:
    vector<int> dp;
    bool dpSolve(vector<int>& nums, int i){
        int n = nums.size();
        if(i >= n - 1)
            return true;
        if(dp[i]!=-1)
            return dp[i];
        
        int reachable = i+nums[i];
        for(int step = i+1; step<=reachable; step++)
            if(dpSolve(nums, step))
                return dp[i] = true;
        
        return dp[i] = false;
        
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==0)    return true;
        // dp.resize(n + 1, -1);
        // return dpSolve(nums, 0);
        
        int goal = n-1;
        
        for(int i = goal; i>=0; i--)
            if(i + nums[i] >= goal)
                goal = i;
        
        return goal==0?true:false;
    }
};