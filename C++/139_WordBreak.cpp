using namespace std;
#include <vector>

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) return true;
        int n = s.length();

        for (int i=1;i<=n;i++) {
            string prefex = s.substr(0,i);
            if(find(wordDict.begin(), wordDict.end(), prefex) != wordDict.end() && wordBreak(s.substr(i), wordDict)) {
                return true;
            }
        }
        return false;
    }
};
