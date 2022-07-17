class Solution {
public:
    int findMin(vector<int>& nums) {
        // Simply use Binary Search and find the pivot element 
        int s = 0, e = nums.size()-1;
        if(nums[s]<nums[e])
            return nums[s];
        
        int mid;
        while(s<e){
            mid = s + (e-s) / 2;
            
            if(nums[0]<=nums[mid])
                s = mid + 1;
            else
                e = mid;
        }
        return nums[s];
    }
};