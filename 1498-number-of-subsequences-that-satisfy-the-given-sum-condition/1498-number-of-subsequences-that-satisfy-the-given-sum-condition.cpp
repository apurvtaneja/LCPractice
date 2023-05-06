class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<=1)
            return 0;
        
        
        sort(nums.begin(), nums.end());
        int res = 0;
        int r = n-1;
        int mod = 1e9+7;
        
        vector<int> pows(n);

        pows[0] = 1;
        for (int i = 1 ; i < n ; ++i)
            pows[i] = pows[i - 1] * 2 % mod;
            
        for(int i = 0; i<n; i++){
            while(((nums[i] + nums[r]) > target) && i <= r)
                r--;
            
            if(i <= r){
                res += pows[r-i];
                res %= mod;
            }
        }
        
        return res;
    }
};