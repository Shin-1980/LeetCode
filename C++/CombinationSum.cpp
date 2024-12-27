using namespace std;
#include <vector>

class Solution {

vector<vector<int>> res;

public:
    void rec(vector<int>& candidates, vector<int> curPair, int target, int curSum, int start) {
        if(target == curSum) {
            this->res.push_back(curPair);
            return;
        }
        else if(target < curSum) return;

        for(int i=start;i<candidates.size();i++) {
            curPair.push_back(candidates[i]);
            rec(candidates, curPair, target, curSum+candidates[i], i);
            curPair.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curPair;
        rec(candidates, curPair, target, 0, 0);

        return this->res;
    }
};