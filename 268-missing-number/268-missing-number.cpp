class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,int>  mp;
        
        for(auto i:nums)    mp[i]++;
        
        for(int i =0; i<nums.size();i++)
            if(mp.find(i)==mp.end())
                return i;
        return nums.size();
    }
};