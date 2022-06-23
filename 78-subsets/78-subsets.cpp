class Solution {
private:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, vector<int>& v, int i){
        if(i==nums.size()){
            ans.push_back(v);
            return;
        }
        
        backtrack(nums, ans, v, i+1);
        
        v.push_back(nums[i]);
        backtrack(nums, ans, v, i+1);
        v.pop_back();
        
    } 
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        backtrack(nums, ans, v, 0);
        return ans;
    }
};