class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int globalMax = nums[0];
        int localMax = 0;
        
        for(auto i: nums){
            localMax += i;
            if(globalMax < localMax)
                globalMax = localMax;
            if(localMax < 0)
                localMax = 0;
        }
        return globalMax;
    }
};