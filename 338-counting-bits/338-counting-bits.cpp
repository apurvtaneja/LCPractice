class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        
        for(int num=0;num<=n;num++){
            int bitCount =0;
            int i = num;
            while(i){
                if(i % 2 == 1)
                    bitCount++;
                i /= 2;
            }
            ans.push_back(bitCount); 
        }
        return ans;
        
    }
};