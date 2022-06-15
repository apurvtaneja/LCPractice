class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int nSum = 0;

        
        for(auto i:nums)    sum += i;
        for(int i = 0; i<=nums.size();i++)     nSum += i;
        
        
        return nSum - sum;
    }
};