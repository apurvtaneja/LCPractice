class Solution {
public:
    string longestPalindrome(string str) {
        string res = "";
        int resLen = 0;
        
        for(int i = 0; i<str.length();i++){
            int s,e;
            s = e = i;
            // For Odd palandromic substrings
            while(s >= 0 && e < str.length() && str[s] == str[e]){
                if((e - s + 1) > resLen){
                    resLen = e - s + 1;
                    res = str.substr(s, resLen);
                }
                s--;    e++;
            }
            s = i;
            e = i+1;
            //For EVEN PAlandromic substrings
            while(s >= 0 && e<str.length() && str[s] == str[e]){
                if((e - s + 1) > resLen){
                    resLen = e - s + 1;
                    res = str.substr(s, resLen);
                }
                s--;    e++;
            }
        }
        return res;
    }
};