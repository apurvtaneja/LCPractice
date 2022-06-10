class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        for(char c:s)   mp[c] += 1;
        
        for(char c:t){
            if(mp.find(c) != mp.end())
                mp[c]--;
            else
                return false;
        }
        
        for(auto i:mp){
            if(i.second > 0)
                return false;
        }
        
        return true;
    }
};