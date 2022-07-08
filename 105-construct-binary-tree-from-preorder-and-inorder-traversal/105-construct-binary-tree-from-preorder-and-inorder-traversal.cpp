
class Solution {
private:
    int preorderIndex;
    unordered_map<int, int> inMap;
    
    TreeNode* solve(int inStart, int inEnd, vector<int>& preorder){
        if(inStart > inEnd)
            return NULL;
        
        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);
        
        root->left = solve(inStart, inMap[rootVal]-1, preorder);
        root->right = solve(inMap[rootVal] + 1, inEnd, preorder);

        return root;            
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        preorderIndex = 0;
        int k = 0;
        for(int i: inorder) inMap[i] = k++;
        
        return solve(0,inorder.size()-1,preorder);
    }
};