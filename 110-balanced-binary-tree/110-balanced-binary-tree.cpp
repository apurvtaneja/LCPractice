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
    int check(TreeNode* root, bool& ans){
        if(!root || !ans)
            return 0;
        
        int leftSubTree = check(root->left, ans);
        int rightSubTree = check(root->right, ans);
        
        if(abs(leftSubTree - rightSubTree) > 1)
            ans = false;

        return max(rightSubTree, leftSubTree) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        int temp = check(root, ans);
        return ans;
    }
};