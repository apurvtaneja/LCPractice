class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        
        int sum = 0;
        while(1){
            while(n){
                int num = n%10; 
                sum += (num * num);
                n /=10;
            }
            if(sum == 1)
                return true;
            
            if(st.find(sum) != st.end())
                return false;
            
            cout<<sum<<endl;
            st.insert(sum);
            n=sum;
            sum = 0;
        }
        return false;
    }
};