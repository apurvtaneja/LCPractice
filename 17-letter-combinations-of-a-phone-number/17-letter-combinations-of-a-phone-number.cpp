class Solution {
private:
    void solve(string digits,vector<string>& ans,string mapping[],int i,string& tempAns)
    {
        if(i>=digits.length()){
            ans.push_back(tempAns);
            return ;
        }
        
        //find digit;
        int phoneDigit = digits[i] - '0';
        //take the corresponding chars associated with that number
        string digitCharSet = mapping[phoneDigit];
        
        //function call each char in that char set;
        for(char c : digitCharSet){
            tempAns.push_back(c);
            solve(digits,ans,mapping,i+1,tempAns);
            tempAns.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0)    return ans;
        
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        string tempAns;
        solve(digits,ans,mapping,0,tempAns);
        return ans;
    };
};