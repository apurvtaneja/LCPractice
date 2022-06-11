class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1, mid = s+((e-s)/2);
        
        while(s<=e){
            int midEl = nums[mid];
            if(midEl == target)
                return mid;
            
            if(target<midEl)
                e = mid-1;
            
            else if(target > midEl)
                s = mid+1;
                
            mid = s+((e-s)/2);
        }
        
        return -1;
    }
};