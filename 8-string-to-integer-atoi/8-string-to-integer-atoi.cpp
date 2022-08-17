class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while(s[i] == ' ')
            i++;
        
        bool isNeg = false;
        
        if(s[i] == '-'){
            isNeg = true;
            i++;
        } 
        else if(s[i] == '+')
            i++;
        
        if(!isdigit(s[i]))
            return 0;
        
        while(s[i] == '0')
            i++;
        
        long int res = 0;
        for(int j = i; j < s.length(); j++){
            if(!isdigit(s[j]))
                break;
            if(res > INT_MAX || res == INT_MAX && s[j] - '0' == '7')  
                return isNeg ? INT_MIN:INT_MAX;
            int digit = s[j] -  '0';
            res = res * 10 + digit;

        }
        if(res > INT_MAX)  
                return isNeg ? INT_MIN:INT_MAX;
        return isNeg?-res:res;
    }
};