class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int sum = 0, largestSubArray = 0;
        
        for(int i = 0; i<nums.size(); i++){
            sum += ((nums[i] == 0)? -1 : 1);
            if(mp.find(sum) == mp.end())    // if not in map
                mp[sum] = i;
            else
                largestSubArray = max(largestSubArray, i - mp[sum]);
        }
        return largestSubArray;
    }
};