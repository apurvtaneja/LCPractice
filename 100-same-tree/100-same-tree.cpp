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
    
    void dfs(TreeNode* root, vector<int>& list){
        if(!root){
            list.push_back(-1);
            return;
        }
        
        list.push_back(root->val);
        
        dfs(root->left,list);
        dfs(root->right,list);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        vector<int> pList;
        vector<int> qList;
        dfs(p,pList);
        dfs(q,qList);

        return pList == qList;
    }
};