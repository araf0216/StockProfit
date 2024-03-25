// Araf Ahmed - program that determines the greatest possible profit that can be made from a list of the daily prices of a stock

int maxProfit(int *prices, int pricesSize)
{
    // initializing pointers for two pointer algorithm - set first pointer to price of first day
    int *p = prices;
    int *q;

    // sets initial profit amount to 0
    int profit = 0;

    // loop that performs two pointer algorithm - second pointer iterates through the daily stock prices
    for (q = p + 1; q < prices + pricesSize; q++)
    {
        // if price decrease detected, then select as best buy time
        if (*q < *p)
        {
            p = q;
        }

        // if price increase detected, select as best sell time if profit is greater than profit from last best sell time
        else if (*q > *p && profit < (*q - *p))
        {
            profit = *q - *p;
        }
    }

    return profit;
}