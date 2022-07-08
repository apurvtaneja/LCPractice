class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sum = 0, largestSubArray = 0;
        
        for(int i = 0; i<nums.size(); i++){
            sum += ((nums[i] == 0)? -1 : 1);
            if(sum==0)
                largestSubArray = max(largestSubArray, i + 1);
            else if(mp.find(sum) != mp.end()) 
                largestSubArray = max(largestSubArray, i - mp[sum]);                
            else
                mp[sum] = i;//Store Sum with Index;
        }
        return largestSubArray;
    }
};