class Solution {
public:
    string simplifyPath(string path) {
        if(path.length() > 0 && path[0] !='/')
            return "";
        
        string res = "";
        vector<string> st;
        
        int j = path.length() - 1;
        while(j>=0 && path[j--] == '/')
            path.pop_back();
        
        int n = path.length();
        
        for(int i = 0; i< n; i++){
            while((i<n) && path[i] == '/')    
                i++;
            
            string s = "";
            
            while((i<n) && path[i] != '/')
                s.push_back(path[i++]);
        
            if(s == ".")
                continue;
            else if(s == ".."){
                if(st.size() > 0)
                    st.pop_back();
            }
            else
                st.push_back(s);
        }
        
        for(string s: st)
            res += '/' + s;
        
        return res==""?"/":res;
    }
};