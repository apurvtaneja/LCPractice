class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int result = nums[0] + nums[1] + nums[nums.size() - 1];
        for(int i = 0; i<nums.size()-2; i++){
            int numOne = nums[i];
            int s = i+1, e = nums.size()-1;
            
            while(s<e){
                int threeSum = numOne + nums[s] + nums[e];
                if(threeSum > target)   e--;
                else   s++;                         // if(threeSum <= target)
                
                if(abs(threeSum - target) < abs(result - target))
                    result = threeSum;
            }
        }
        return result;
    }
};