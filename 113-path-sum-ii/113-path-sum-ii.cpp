/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool isSeen(vector<int>& v, vector<vector<int>>& ans){
        for(auto vec:ans)
            if(v == vec)
                return true;
        return false;
    }
    void dfs(TreeNode* root, int sum, vector<int> v, int targetSum, vector<vector<int>>& ans){
        if(!root)
            return;
        
            
        sum += root->val;
        v.push_back(root->val);
        
        if(sum == targetSum && !root->left && !root->right)
            ans.push_back(v);
        
        dfs(root->left, sum, v, targetSum, ans);
        dfs(root->right, sum, v, targetSum, ans);
        v.pop_back();
        sum -= root->val;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        // if(!root || targetSum == 0)
        //     return {};
        
        vector<vector<int>> ans;
        dfs(root, 0, {}, targetSum, ans);
        return ans;
    }
};