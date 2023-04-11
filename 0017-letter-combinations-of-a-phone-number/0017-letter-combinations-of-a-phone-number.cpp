class Solution {
private:
    vector<string> res;
    void solve(string digits, unordered_map<int, string> &mp, int i, string temp){
        if(i>=digits.length()){
            res.push_back(temp);
            return ;
        }
        
        int digit = digits[i] - '0';
        string characters = mp[digit];
        
        for(int j = 0; j<characters.length(); j++){
            temp.push_back(characters[j]);
            solve(digits, mp, i+1,temp);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
            return res;
        unordered_map<int, string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        solve(digits, mp, 0, "");
        return res;
    }
};