class Solution {
private:
    vector<int> getDifference(vector<int>& nums1, vector<int>& nums2){
        
        unordered_set<int> st;
        
        for(int i = 0; i < nums1.size(); i++){
            int flag = 0;
            for(int j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j])
                    flag = 1;
            }
            if(!flag)
                st.insert(nums1[i]);
        }
        
        return vector<int>(st.begin(), st.end());
    }
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {        
        return {getDifference(nums1, nums2), getDifference(nums2, nums1)};
    }
};