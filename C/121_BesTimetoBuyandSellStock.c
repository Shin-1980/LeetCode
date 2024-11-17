#define MAX(a,b) ((a>b) ? a: b)

int maxProfit(int* prices, int pricesSize) {
    int maxPrice = 0;
    int maxProfit = 0;

    for (int i=(pricesSize-1);i>-1;i--) {
        maxPrice = MAX(maxPrice,prices[i]);
        maxProfit = MAX(maxProfit,(maxPrice-prices[i]));
    }

    return maxProfit;
}

/*
The goal of this problem is to return the maximum profit from a single buy-and-sell transaction, 
calculated as the difference between the buying price and the selling price. 
I use a memoization to solve this.
In this approach, the algorithm iterates through the array from the end to the beginning. 
During the iteration, two values are tracked: 
the maximum price encoutnerd so far and the maximum profit. 
At each step, the maximum price is updated if the current price is greater, 
and the maximum profit is updated by calculating the difference between the maximum price and the current price.
When the iteration completes, the maximum profit is returned as the result.
*/