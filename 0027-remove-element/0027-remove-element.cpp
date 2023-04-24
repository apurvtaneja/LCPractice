class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        
        int k;
        for(int i = 0; i<n; i++)
            if(nums[i] == val){
                k = i;
                break;
            }
        
        for(int i = k+1; i<n; i++){
            if(nums[i] != val)
                nums[k++] = nums[i];
        }
        return k;
    }
};