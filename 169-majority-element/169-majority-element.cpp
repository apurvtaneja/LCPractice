class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        for(int i:nums)     mp[i] += 1;
        
        int maxEl = INT_MIN;
        int maxOcc = 0;
        for(auto i:mp){
            if(i.second>maxOcc){
                maxEl = i.first;
                maxOcc = i.second;                 
            }
        }
        return maxEl;
    }
};