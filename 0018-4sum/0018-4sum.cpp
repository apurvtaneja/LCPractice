class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());        
        int n = nums.size();
        
        vector<vector<int>> res;
        
        for(int i = 0; i<n; i++){
            if(i>0 && nums[i-1] == nums[i]) continue;
            
            int firstNum = nums[i];            
            for(int j = i+1; j<n; j++){
                if(j>i+1 && nums[j]==nums[j-1])
                    continue;
                int secondNum = nums[j];
                
                long long newTarget = (long long)target - firstNum - secondNum;
                
                int s, e;
                s = j + 1 , e = n-1;
                
                while(s<e){
                    long long twoSum = nums[s] + nums[e];
                    
                    if(twoSum == newTarget){
                        res.push_back({firstNum, secondNum, nums[s], nums[e]});
                        s++;
                        while(s<e && nums[s]==nums[s-1])
                            s++;
                    }
                    else if(twoSum > newTarget)
                        e--;
                    else if(twoSum < newTarget)
                        s++;
                }
            }
        }
        
        return res;
    }
};