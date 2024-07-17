class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int tempProfit = 0;
        int n = prices.size();
        int buyDate = prices[0];
        int sellDate;
        for( int i = 1; i<n; i++ )
        {
            sellDate = prices[i];
            tempProfit = sellDate - buyDate;
            if( tempProfit > profit ) { profit = tempProfit; }

            if( tempProfit <= 0 )
            {
                buyDate = prices[i];
            }
        }
    return profit;
    }
};
