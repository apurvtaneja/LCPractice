class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-1;
        vector<int> ans;
        while(s<e){
            int numOne = nums[s];   int numTwo = nums[e];
            if(numOne + numTwo == target){
                ans.push_back(++s);   ans.push_back(++e);
                return ans;
            }
            else if(numOne + numTwo > target )   e--;
            else if(numOne + numTwo < target )   s++;
        }
        return ans;
    }
};