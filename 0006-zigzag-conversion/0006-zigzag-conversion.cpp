class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        int n = s.length();
        vector<vector<char>> res(numRows, vector<char>(n, ' '));
        
        int i, j, k;
        
        i = j = k = 0;
        
        
        while(k < n){
            while(i < numRows && k < n)
                res[i++][j] = s[k++];

            i = numRows - 2;
            j++;
            
            while(i >= 0 && k < n)
                res[i--][j++] = s[k++];
            
            i += 2;
            j--;
        }
        
        // for(auto v: res){
        //     for(char c: v){
        //         cout<< c<<" ";
        //     }
        //     cout<<'\n';
        // }
        
        string ans;
        
        for(auto v: res)
            for(char c: v)
                if(c != ' ')
                    ans+=c;
        
        return ans;
    }
};