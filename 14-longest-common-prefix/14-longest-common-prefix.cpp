class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size() - 1;
        sort(strs.begin(),strs.end());
        string a = strs[0];
        string b = strs[n];
        
        string ans = "";
        for(int i = 0; i<a.length();i++){
            if(a[i] == b[i])
                ans.push_back(a[i]);
            else
                break;
        }
        return ans;
    }
};