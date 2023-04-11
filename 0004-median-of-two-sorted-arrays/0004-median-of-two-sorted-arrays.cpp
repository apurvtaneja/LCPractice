class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sortedArr;
        
        int i, j;
        i = j = 0;
        
        while(i<nums1.size() && j< nums2.size()){
            if(nums1[i] < nums2[j])
                sortedArr.push_back(nums1[i++]);
            else
                sortedArr.push_back(nums2[j++]);
        }
        while(i<nums1.size())
            sortedArr.push_back(nums1[i++]);
        while(j<nums2.size())
            sortedArr.push_back(nums2[j++]);
        
        int mid = sortedArr.size() / 2;
        
        if(sortedArr.size() % 2 == 1) // ODD
            return double(sortedArr[mid]);
        else{
            double res = (sortedArr[mid] + sortedArr[mid-1])/2.0;
            return res;
        }
    }
};