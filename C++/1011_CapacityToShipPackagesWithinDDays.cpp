using namespace std;
#include <vector>

class Solution {
public:
    int calday(vector<int>& weights, int maxLoad) {
        int days=1;
        int curLoad = 0;

        for(auto w:weights) {
            curLoad += w;
            if (curLoad > maxLoad) {
                days += 1;
                curLoad = w;
            }
            else if(curLoad == maxLoad && w != weights[weights.size()-1]) {
                days += 1;
                curLoad = 0;
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int r=0;
        int l=0;

        for(auto w:weights) {
            r += w;
            l = max(l,w);
        }

        while(l<r) {
            int m = (l+r) / 2;
            int shipdays = calday(weights, m);
            
            if (days < shipdays) l = m + 1;
            else r = m;
        }

        return l;
    }
};