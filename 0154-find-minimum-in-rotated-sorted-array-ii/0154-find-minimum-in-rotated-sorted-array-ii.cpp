class Solution {
public:
    int findMin(vector<int>& nums) {
        int s, e, mid;
        s = 0, e = nums.size() - 1;
        
        if(nums[s] < nums[e])
            return nums[s];
        
        while(s < e){
            mid = s + (e - s) / 2;            
            if(nums[e] < nums[mid]){
                s = mid+1; 
            }
            else if(nums[e] > nums[mid])
                e = mid;
            else
                e--;
        }
        return nums[s];
    }
};