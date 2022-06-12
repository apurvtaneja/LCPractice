// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n == 1) return n;
        
        int s = 1, e = n, mid = s + ((e-s)/2);
        
        while(s<e){
            if(!isBadVersion(mid-1) && isBadVersion(mid))
                return mid;
            
            bool isMidBad = isBadVersion(mid);
            
            if(isMidBad == true)
                e = mid;
            
            if(isMidBad == false)
                s = mid+1;
            
            mid = s + ((e-s)/2);
        }
        return mid;
    }
};

// 1 2 3 4


