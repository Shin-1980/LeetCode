using namespace std;
#include <vector>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minV=prices[0];
        int maxD=0;

        for(auto price:prices) {
            minV = min(minV, price);
            maxD = max(maxD, price - minV);
        }

        return maxD;
    }
};
