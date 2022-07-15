class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() == 1)
            return {{strs[0]}};
        
        unordered_map<string, vector<string>> mp;
        
        for(auto s: strs){
            string temp= s;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(s);
        }
        
        vector<vector<string>> ans;
        for(auto& m: mp)
            ans.push_back(m.second);
        
        return ans;
    }
};