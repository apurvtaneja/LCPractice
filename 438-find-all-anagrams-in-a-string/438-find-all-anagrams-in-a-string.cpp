class Solution {
private:
    bool areEqual(int *sMap, int *pMap){
        for(int i=0;i<26;i++)
            if(sMap[i] != pMap[i])
                return false;
        
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
         if(s.length()<p.length())       return {};
        
        vector<int> ans;
        
        int pMap[26] =  {0};
        int sMap[26] =  {0};

        for(auto c: p)  pMap[c - 'a']++;
        
        int windStart = 0, windEnd = p.size()-1;
        
        for(int i = 0; i <= windEnd; i++)
            sMap[s[i] - 'a']++;
        
        if(areEqual(sMap,pMap))
                ans.push_back(windStart);
        
        windEnd++;
        
        while(windEnd < s.size()){
            //Include next index and increment windEnd.
            sMap[s[windEnd++] - 'a'] += 1;
            
            //Exclude previous Index and increment windStart.
            sMap[s[windStart++] - 'a'] -= 1;
            
            if(areEqual(sMap,pMap))
                ans.push_back(windStart);
        }
        return ans;
    }
};