class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        int windSize = s1.length();
        vector<int> s1Map(26,0);
        vector<int> s2Map(26,0);
        
        for(auto c: s1)
            s1Map[c - 'a']++;
        
        for(int i = 0; i< windSize; i++)   //Initializing 1st Window
            s2Map[s2[i] - 'a']++;
        
        if(s1Map == s2Map)
                return true;
        
        int i = 0;
        int j = windSize;
        
        while(j<s2.length()){
            s2Map[s2[i++] - 'a']--; //excluding
            s2Map[s2[j++] - 'a']++; //including
            
            if(s1Map == s2Map)
                return true;
        }
        return false;
    }
};