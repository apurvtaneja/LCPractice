class Solution {
private:
bool solve(TreeNode* root, TreeNode* &target, vector<TreeNode*> &path){
if(!root)   return false;
path.push_back(root);
if(root->val == target->val)    return true;
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
int size = min(pPath.size(), qPath.size());
TreeNode* prev;
for(int i = 0; i< size; i++){
if(pPath[i]->val!=qPath[i]->val)
return prev;
prev = pPath[i];
}
return NULL;
}
};