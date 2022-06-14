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
    bool areEqual(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL)  return true;
        
        if(p != NULL && q == NULL || p == NULL && q != NULL|| (p->val !=q->val))
            return false;
        
        return areEqual(p->left, q->left) && areEqual(p->right, q->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root || !subRoot)   return false;
        
        if(root->val == subRoot->val){
            bool x = areEqual(root, subRoot);
            if(x)
                return x;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};