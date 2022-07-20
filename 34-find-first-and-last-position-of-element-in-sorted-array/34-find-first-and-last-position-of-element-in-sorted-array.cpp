class Solution {
    int help(vector<int>& nums, int target, int s, int e, bool isFirst) {
        int ans = -1;
        while(s<=e){
            int mid = s + (e - s)/2;
            
            if(nums[mid] == target){
                ans = mid;
                if(isFirst)
                    e = mid-1;
                else
                    s = mid + 1;
            }
            else if(target>nums[mid])
                s = mid + 1;
            else 
                e = mid - 1;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-1;
        
        return {help(nums, target, s, e, 1), help(nums, target, s, e, 0)};
    }
};