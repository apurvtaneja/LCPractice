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
    TreeNode* solve(int preStart, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& inMap){
        if(preStart >= preorder.size() || inStart > inEnd)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int inIndex = inMap[root->val];
        
        root->left = solve(preStart + 1, inStart, inIndex-1, preorder, inorder, inMap);
        root->right = solve(preStart + inIndex - inStart + 1, inIndex+1, inEnd, preorder, inorder, inMap);

        return root;            
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        int k = 0;
        for(int i: inorder) inMap[i] = k++;
        
        return solve(0,0,inorder.size()-1,preorder, inorder, inMap);
    }
};