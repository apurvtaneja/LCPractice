class Solution {
public:
    int longestPalindrome(string s) {
        
        int n = s.length();
        int maxPalindrome = 0;
        bool oneOne = false;
        
        if(n == 1) return 1;
        
        unordered_map<char,int> mp;
        
        for(char c:s)   mp[c] += 1;
        
        
        for(auto i:mp){
            maxPalindrome += i.second/2 * 2;
            
            if(maxPalindrome % 2 ==0 && i.second % 2 == 1)
                
               maxPalindrome++;
        }
        return maxPalindrome;
    }
};

/*

b -> 1
a -> 3
n -> 2
s -> 1





*/