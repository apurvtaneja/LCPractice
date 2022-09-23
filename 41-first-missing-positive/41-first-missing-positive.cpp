class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        for(int i: nums)
            mp[i]++;
        
        int maxPositive = nums.size();
        
        for(int i = 1; i<=maxPositive; i++){
            if(mp[i] == 0)
                return i;
        }
        
        return maxPositive+1;
    }
};