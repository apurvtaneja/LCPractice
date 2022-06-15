class Solution {
public:
    bool backspaceCompare(string s, string t) {
        cout<<t<<endl;
        string sTemp = "", tTemp = "";
        
        for(char c:s){
            if(c == '#' && !sTemp.empty())
                sTemp.pop_back();
            else{
                if(c != '#')                
                    sTemp.push_back(c);
            }
        }
        for(char c:t){
            if(c == '#' && !tTemp.empty())
                tTemp.pop_back();
            else{
                if(c != '#')
                    tTemp.push_back(c);
            }
                
        }
        cout<<sTemp<<endl;
        cout<<tTemp<<endl;
        
        return sTemp == tTemp;
    }
};