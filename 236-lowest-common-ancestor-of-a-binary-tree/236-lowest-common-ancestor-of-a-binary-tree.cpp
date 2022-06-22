/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool solve(TreeNode* root, TreeNode* &target, vector<TreeNode*> &path){
        if(!root)   return false;
        path.push_back(root);
        if(root->val == target->val)    return true;
        if(solve(root->left, target, path) ||
            solve(root->right, target, path))
            return true;
        path.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val == p->val || root->val == q->val) return root;
        vector<TreeNode*> pPath, qPath;
        solve( root, p, pPath);
        solve( root, q, qPath);
        for(auto i:pPath)   cout<<i->val<<" ";
        cout<<endl;
        for(auto i:qPath)   cout<<i->val<<" ";
        cout<<endl;
        for(int i = pPath.size()-1; i>=0; i--)
            for(int j = qPath.size()-1; j>=0; j--)
                if(pPath[i]->val == qPath[j]->val)
                    return qPath[j];
            
        return NULL;
    }
};