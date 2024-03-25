// Araf Ahmed - program that determines the greatest possible profit that can be made from a list of the daily prices of a stock
#include <stdio.h>

int maxProfit(int *prices, int pricesSize, int *buy_date, int *sell_date)
{
    // initializing pointers for two pointer algorithm - set first pointer to price of first day
    int *p = prices;
    int *q;

    // sets initial profit amount to 0
    int profit = 0;
    // int buy_date;
    // int sell_date;

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
            *buy_date = p - prices;
            *sell_date = q - prices;
        }
    }

    return profit;
}

int main()
{
    int buy_date;
    int sell_date;

    int pricesSize;
    scanf("%d", &pricesSize);
    int prices[pricesSize];
    for (int *p = prices; p < prices + pricesSize; p++)
    {
        int n;
        scanf("%d", &n);
        *p = n;
    }

    int profit = maxProfit(prices, pricesSize, &buy_date, &sell_date);

    printf("Buy date: Day %d\n", buy_date + 1);
    printf("Sell date: Day %d\n", sell_date + 1);
    printf("Greatest profit: $%d", profit);

    return 0;
}
