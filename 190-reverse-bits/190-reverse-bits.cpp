class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        long long int revBits = 0;
        for(int i = 0; i<32;i++){
            if(n&1)
                revBits |= 1;
                
            revBits <<= 1;
            n >>= 1;
        }
        return revBits>>1;
    }
};