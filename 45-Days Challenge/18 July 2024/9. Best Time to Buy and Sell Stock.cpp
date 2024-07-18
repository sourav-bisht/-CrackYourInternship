class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int tempMax = 0;
        int temp = 0;
        int n = prices.size();
        int buyPrice = prices[0];
        int sellPrice;
        for( int i = 1; i<n; i++ )
        {
            sellPrice = prices[i];
            temp = sellPrice - buyPrice;
            if( temp > tempMax )
            {
                profit = profit - tempMax + temp;
                tempMax = temp;
            }
            else if( temp < tempMax )
            {
                buyPrice = prices[i];
                tempMax = 0;
            }

            if( temp <= 0 )
            {
                temp = 0;
                buyPrice = prices[i];
            }
        }
        return profit;
    }
};
