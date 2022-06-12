class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        
        for(char c: magazine)   
            mp[c] += 1;
        
        for(char c : ransomNote){
            if(mp.find(c) != mp.end()){
                if(mp[c])
                    mp[c]--;
                else
                    return false;
            }
            else
                return false;
        }
        return true;
    }
};