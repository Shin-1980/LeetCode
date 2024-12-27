using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1; // Handle the case where n is 0
        if (n == 1) return x; // Base case for n == 1
        
        if (n < 0) {
            x = 1 / x;
            if (n == INT_MIN) {
                return x * myPow(x, INT_MAX);
            }
            n = -n;
        }

        double res = myPow(x, n / 2);
        res *= res;

        if (n % 2 == 1) res *= x;

        return res;

    }
};