class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroIndex = 0;
        
        int n = nums.size();

        for(int i=0; i<n; i++)
            if(nums[i])
                swap(nums[zeroIndex++], nums[i]);

    }
};




