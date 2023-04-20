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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*, int>> q;
        int maxWidth = 1;
        
        q.push({root, 1});
        
        while(!q.empty()){
            int size = q.size();
            
            int start = q.front().second;
            int end = q.back().second;
            int width = (long long)end - start + 1;
            maxWidth = max(maxWidth, width);
            
            for(int i = 0; i< size; i++){
                TreeNode* node = q.front().first;
                int idx = q.front().second;
                q.pop();
                
                if(node->left)
                    q.push({node->left, 2LL*idx});
                if(node->right)
                    q.push({node->right, 2LL*idx+1});
            }
        }
        
        return maxWidth;
    }
};