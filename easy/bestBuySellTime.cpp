// Problem: Best Time to Buy and Sell Stock

// We traverse from the end, tracking the maximum future price (maxd)
// For each price[i], we check if selling at maxd gives profit.
// If prices[i] > maxd, update maxd because we found a better selling day.

class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int maxd = prices[prices.size() - 1];  
        int maxProfit = 0;                          
        
        for(int i = prices.size()-2; i >= 0; i--) {
            if(maxd > prices[i]) {
                maxProfit = max(maxProfit, maxd - prices[i]);
            } 
            else maxd = prices[i];
        }
        return maxProfit;
    }
};
