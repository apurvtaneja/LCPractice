class Solution {
public:
    string longestPalindrome(string str) {
        string res = "";
        int reslen = 0;
        for(int i=0; i< str.length(); i++){
            int s,e;
            s = e = i;
            
            while(s>=0 && e<str.length() && str[s] == str[e]){
                if(reslen < e-s+1){
                    reslen = e-s+1;
                    res = str.substr(s, reslen);
                }
                s--;
                e++;
            }
            
            s = i;
            e = i+1;
            
            while(s>=0 && e<str.length() && str[s] == str[e]){
                if(reslen < e-s+1){
                    reslen = e-s+1;
                    res = str.substr(s, reslen);
                }
                s--;
                e++;
            }
                
        }
        return res;
    }
};