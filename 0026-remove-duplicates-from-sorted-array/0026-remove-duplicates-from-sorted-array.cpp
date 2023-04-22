class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int i = 0;
        int n = nums.size();
        
        while(i<n){
            if(nums[k] != nums[i])
                nums[++k] = nums[i];
            i++;
        }
        // cout<<k+1;
        return k+1;
    }
};