class Solution {
private:
    string countSort(string s){
        int arr[26] = {0};
        for(char c: s)
            arr[c - 'a']++;
        
        string t = "";
        for(int i = 0; i < 26; i++)
                t += string(arr[i], 'a' + i);
        
        return t;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() == 1)
            return {{strs[0]}};
        
        unordered_map<string, vector<string>> mp;
        
        for(auto s: strs){
            // string temp= s;
            // sort(temp.begin(), temp.end());
            mp[countSort(s)].push_back(s);
        }
        
        vector<vector<string>> ans;
        for(auto& m: mp)
            ans.push_back(m.second);
        
        return ans;
    }
};