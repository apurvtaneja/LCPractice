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
    int maxLen = 0;
    void maxZigZag(TreeNode* root, int goLeft, int len){
        if(!root)
            return;
        
        maxLen = max(maxLen, len);
        
        if(goLeft){
            maxZigZag(root->left, false, len + 1);
            maxZigZag(root->right, true, 1);
        }
        else{
            maxZigZag(root->left, false, 1);
            maxZigZag(root->right, true, len + 1);
        }
        
}
public:
    int longestZigZag(TreeNode* root) {
        maxZigZag(root, false, 0);
        maxZigZag(root, true, 0);
        
        return maxLen;
    }
};