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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        
        bool reverse = false;
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);
            
            for(int i = 0; i<size;i++){
                auto node = q.front();
                q.pop();
                if(node->left)  q.push(node->left);
                if(node->right)  q.push(node->right);
                
                int index = reverse ? size - i - 1: i;  
                level[index] = node->val;
            }
            ans.push_back(level);
            reverse = !reverse;
        }
        return ans;
    }
};