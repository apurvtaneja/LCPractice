class Solution {    
private:
    int binarySearch(vector<int>& nums, int s, int e, int x){
        while(s<=e){
            int mid = s + ((e - s) / 2);
            if(nums[mid]==x)
                return mid;
            
            if(x > nums[mid])
                s = mid +1;
            else
                e = mid-1;
        }
        return -1;
    }
    int findPivot(vector<int>& nums, int s, int e){
        if(nums[s]<nums[e])
            return s;
        while(s<e){
            int mid = s + ((e - s) / 2);
            
            if(nums[mid]>=nums[0])
                s = mid + 1;
            else
                e = mid;
        }
        return s;
    }
public:
    int search(vector<int>& nums, int target) {
        int e = nums.size()-1;
        int pivot = findPivot(nums, 0, e);
        
        if(target >= nums[pivot] && target <= nums[e])
            return binarySearch(nums, pivot, e, target);
        else
            return binarySearch(nums, 0, pivot-1, target);
        
    }
};