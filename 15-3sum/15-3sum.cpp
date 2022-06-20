class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i = 0; i <nums.size();i++){
            if(i>0 && (nums[i-1] == nums[i])) continue;
            int numOne = nums[i];
            int s = i+1, e = nums.size()-1;
            
            
            while(s<e){
                vector<int> temp;
                int threeSum = numOne + nums[s] + nums[e];
                if(threeSum == 0){
                    temp.push_back(numOne);
                    temp.push_back(nums[s]);
                    temp.push_back(nums[e]);
                    ans.push_back(temp);
                    s++;
                    while(nums[s] == nums[s-1] && s<e)  s++;
                }
                else if(threeSum > 0)   e--;
                else if(threeSum < 0)   s++;
            }
            
        }
        return ans;
    }
};