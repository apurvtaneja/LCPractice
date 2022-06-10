class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int minBuy = INT_MAX;
        int maxProfit = 0;
        
        for(auto i: prices)
        {
            if(i < minBuy)    minBuy = i;
            int profit = i - minBuy;
            if(profit > maxProfit)  maxProfit = profit;
        }
       
        
        return maxProfit;
    }
};