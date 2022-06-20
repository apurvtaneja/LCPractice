class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-1;
        vector<int> ans;
        while(s<e){
            int numOne = nums[s];   int numTwo = nums[e];
            int twoSum = numOne + numTwo;
            if(twoSum == target){
                ans.push_back(++s);   ans.push_back(++e);
                return ans;
            }
            else if(twoSum > target )   e--;
            else if(twoSum < target )   s++;
        }
        return ans;
    }
};