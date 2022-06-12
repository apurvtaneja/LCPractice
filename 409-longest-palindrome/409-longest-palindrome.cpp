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
            if(i.second % 2 ==0)
               maxPalindrome += i.second;
            else
            {
                maxPalindrome += i.second-1; 
                oneOne = true;
            }
        }
        if(oneOne)
            return maxPalindrome + 1;
        
        return maxPalindrome;
    }
};

/*

b -> 1
a -> 3
n -> 2
s -> 1





*/