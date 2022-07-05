class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low,mid,high;
        low = mid = 0;
        high = n-1;
        
        while(high>=mid){
            if(nums[mid] == 0)
                swap(nums[mid++], nums[low++]);
            else if(nums[mid] == 1)
                mid++;
            else if(nums[mid] == 2)
                swap(nums[mid], nums[high--]);
        }
    }
};