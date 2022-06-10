class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int maxSell = INT_MIN;
        int maxProfit = 0;
        
        for(int i = n-1; i >= 0 ; i--)
        {
            if(prices[i] > maxSell)    maxSell = prices[i];
            
            else{
                int profit = maxSell - prices[i];
                if(profit > maxProfit)  maxProfit = profit;
            }
        }
        
        return maxProfit;
    }
};