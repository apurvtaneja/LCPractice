class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.length()<p.length())       return {};
        
        vector<int> ans;
        vector<int> pMap(26,0);
        vector<int> window(26,0);
        
        int windStart = 0, windEnd = p.size()-1;
        
        for(auto c: p)  pMap[c - 'a']++;
        
        // First Window
        for(int i = 0; i <= windEnd; i++)
            window[s[i] - 'a']++;
        
        if(window == pMap)
                ans.push_back(0);
        
        // Increment so we can include next element in our window.
        windEnd++; 
        
        while(windEnd < s.size()){
            //Include next index and increment windEnd.
            window[s[windEnd++] - 'a'] += 1;
            
            //Exclude previous Index and increment windStart.
            window[s[windStart++] - 'a'] -= 1;
            
            if(window == pMap)
                ans.push_back(windStart);
        }
        return ans;
    }
};