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
    void morrisTraversal(TreeNode* root, vector<int>& inorderRes){
        if(!root)
            return;
        auto curr = root;
        while(curr){
            if(curr->left){
                auto pred = curr->left;
                while(pred->right && pred->right != curr)
                    pred = pred->right;
                if(!pred->right){
                    pred->right = curr;
                    curr = curr->left;
                }
                else{
                    pred->right = NULL;
                    inorderRes.push_back(curr->val);
                    curr = curr->right;
                }
            }
            else{
                inorderRes.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorderRes;
        morrisTraversal(root, inorderRes);
        return inorderRes;
    }
};