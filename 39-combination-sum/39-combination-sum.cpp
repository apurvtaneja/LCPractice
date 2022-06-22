class Solution {
private:
    void backtrack(int i, int target, vector<int>& nums, vector<vector<int>>& res, vector<int>& v){
        if(i==nums.size()){
            if(target == 0)
                res.push_back(v);
            return;
        }
        
        if(nums[i]<=target){
            v.push_back(nums[i]);
            backtrack(i, target - nums[i], nums, res, v);
            v.pop_back();
        }
        backtrack(i+1,target, nums, res, v);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> v;
        backtrack(0, target, candidates, res, v);
        return res;
    }
};