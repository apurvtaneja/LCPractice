class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        
        int l =0; 
        int n = s.length();
        int maxSubStr = 0;
        
        for(int r = 0; r < n; r++){
            if(charSet.find(s[r]) != charSet.end()){
                while(l!=r && s[l]!=s[r])
                    charSet.erase(s[l++]);
                charSet.erase(s[l++]); 
            }
            charSet.insert(s[r]);
            maxSubStr = max(maxSubStr, r-l+1);
        }
        return maxSubStr;
    }
};