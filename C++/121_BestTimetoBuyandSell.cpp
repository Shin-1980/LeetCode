class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mprice = prices[prices.size()-1];
        int ret = 0;

        for (int i=prices.size()-2;i>-1;i--) {
            mprice = max(prices[i], mprice);
            ret = max(ret, mprice - prices[i]);
        }

        return ret;
    }
};

// algorithm: memoization