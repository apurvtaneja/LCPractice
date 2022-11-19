class Solution {
public:
    int majorityElement(vector<int>& nums) {
            
        int ele, cnt = 0;
        
        for(int i:nums){
            if(cnt == 0)
                ele = i;
            if(ele == i)
                cnt++;
            else
                cnt--;
        }
        
        return ele;
        
        
//         unordered_map<int,int> mp;
        
//         for(int i:nums)     mp[i] += 1;
        
//         int maxEl = INT_MIN;
//         int maxOcc = 0;
//         for(auto i:mp){
//             if(i.second>maxOcc){
//                 maxEl = i.first;
//                 maxOcc = i.second;                 
//             }
//         }
//         return maxEl;
    }
};