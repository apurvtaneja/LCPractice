class Solution {
public:
    int maxVowels(string s, int k) {
        if(s.length() < k)
            return 0;
        
        unordered_set<char> st;
        st.insert('a');        
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');

        int n = s.length();
        int max_vowels = 0;
        int t_vowels = 0;
        
        for(int i = 0; i < k; i++)
            if(st.find(s[i]) != st.end())
                t_vowels++;
        
        max_vowels = max(max_vowels, t_vowels);
        
        for(int i = 0, j = k; j < n; i++, j++){
            
            //remove the old char if it is a vowel
            if(st.find(s[i]) != st.end())
                t_vowels--;
            
            //remove the new char if it is a vowel
            if(st.find(s[j]) != st.end())
                t_vowels++;
            
            max_vowels = max(max_vowels, t_vowels);
        }
        
        return max_vowels;
    }
};