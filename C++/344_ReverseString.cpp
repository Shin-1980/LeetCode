#include <iostream>
#include <vector>

class Solution {
public:
    void reverseString(vector<char>& s) {
        char tmp;
        int l = 0;
        int r = s.size()-1;

        while (l < r) {
            swap(s[l],s[r]);
            l++;
            r--;
        }

    }
};

