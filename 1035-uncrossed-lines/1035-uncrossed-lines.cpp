class Solution {
private:
    vector<vector<int>> dp;
    int dpSolve(vector<int>& nums1, vector<int>& nums2, int i, int j){
        if(i<=0 || j<=0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(nums1[i-1] == nums2[j-1])
            dp[i][j] = 1 + dpSolve(nums1, nums2, i-1,j-1);
        else
            dp[i][j] = max(dpSolve(nums1, nums2, i-1,j),dpSolve(nums1, nums2, i,j-1));
        return dp[i][j];
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        dp.resize(m+1,vector<int>(n+1,-1));
        
        return dpSolve(nums1, nums2, m, n);
    }
};