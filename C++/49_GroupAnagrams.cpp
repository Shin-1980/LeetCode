using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> ht;

        for (auto& str: strs){
            string s = str;
            sort(s.begin(), s.end());
            ht[s].emplace_back(str);
        }

        vector<vector<string>> ans;

        for (auto& h: ht) {
            ans.emplace_back(h.second);
        }

        return ans;
    }
};
