```
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
​
return pList == qList;
}
};
```