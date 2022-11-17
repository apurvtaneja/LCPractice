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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)
            return {};
        
        map<int ,map<int, multiset<int>>> nodes;
        
        queue<pair<TreeNode*, pair<int, int> >> q;
        
        vector<vector<int>> ans;
        
        q.push(make_pair(root, make_pair(0,0))); // root, horizontal Distance, level
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            auto node = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            nodes[hd][lvl].insert(node->val);
            
            if(node->left)
                q.push(make_pair(node->left,make_pair(hd-1,lvl+1)));
            if(node->right)
                q.push(make_pair(node->right,make_pair(hd+1,lvl+1)));    
        }
        
        for(auto i: nodes){
            vector<int> v;
            for(auto j:i.second){
                for(auto k:j.second)
                    v.push_back(k);    
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};