class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long int rev = 0;
        int dup = x;
        
        while(dup){
            int lastDigit = dup % 10;
            rev = rev * 10 + lastDigit;
            dup /= 10;
        }
        cout<<rev;
        return rev == x;
    }
};