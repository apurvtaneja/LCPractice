class Solution {
private:
    vector<int> getDifference(vector<int>& nums1, vector<int>& nums2){
        
        unordered_set<int> st1, st2;
        
        for(int j: nums2)
            st2.insert(j);
        
        for(int i: nums1)
            if(st2.find(i) == st2.end())
                st1.insert(i);
        
        return vector<int>(st1.begin(), st1.end());
    }
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {        
        return {getDifference(nums1, nums2), getDifference(nums2, nums1)};
    }
};