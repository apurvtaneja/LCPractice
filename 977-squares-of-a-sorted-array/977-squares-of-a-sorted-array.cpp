class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int s=0, e, k;
        k = e = nums.size()-1;
        vector<int> res(nums.size());
        while(s<=e){
            if(abs(nums[s]) > abs(nums[e]))
                res[k--] = nums[s] * nums[s++];
            else
                res[k--] = nums[e] * nums[e--];
            
        }
        return res;
    }
};