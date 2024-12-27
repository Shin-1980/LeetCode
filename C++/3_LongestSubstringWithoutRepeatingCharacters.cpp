using namespace std;
#include <vector>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> ht(256,false);

        int maxCount=0;
        int l=0;
        int r=0;

        for (auto c:s) {
            while(ht[c]){
                ht[s[l++]]=false;
            }
            ht[c]=true;

            maxCount = max(maxCount, r-l+1);
            r++;
        }

        return maxCount;
        
    }
};