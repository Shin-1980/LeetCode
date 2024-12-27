using namespace std;
#include <vector>

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string cur;
        vector<string> ans;

        backtrack(n,n,cur,ans);

        return ans;
    }

private:
    void backtrack(int l, int r, string& cur, vector<string>& ans) {
        if (l == 0 && r == 0) {
            ans.push_back(cur);
            return;
        }

        if (l > 0) {
            cur.push_back('(');
            backtruck(l-1,r,cur,ans);
            cur.pop_back();
        }

        if (l < r) {
            cur.push_back(')');
            backtruck(l,r-1,cur,ans);
            cur.pop_back();
        }
    }

};