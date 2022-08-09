class Solution {
private:
    vector<vector<int>> dp;
    int dpSolve(const vector<int> &A, int i, int prevIdx){
        int n = A.size();
        if(i==n)
            return 0;
        if(dp[i][prevIdx+1] != -1)
            return dp[i][prevIdx+1];

        int notTake = dpSolve(A, i+1, prevIdx);

        int take = 0;
        if(prevIdx == -1 || A[i] > A[prevIdx])
            take = 1 + dpSolve(A, i+1, i);

        return dp[i][prevIdx+1] = max(take, notTake);
    }
public:
    int lengthOfLIS(vector<int>& A) {
        int n = A.size();

        dp.resize(n+1,vector<int>(n+1,-1));

        return dpSolve(A, 0, -1);
    }
};