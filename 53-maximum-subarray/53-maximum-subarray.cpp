class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int globalMax = nums[0];
        int localMax = 0;
        
        for(auto i: nums){
            localMax += i;
            globalMax = max(globalMax, localMax);
            localMax = max(localMax,0);
        }
        return globalMax;
    }
};