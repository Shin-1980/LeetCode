using namespace std;
#include<unordered_map>
#include<string>

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> ht;

        for (auto& c: s) ht[c]++;
        
        for (int i=0;i<s.size();i++) {
            if (ht[s[i]] == 1) return i;
        }

        return -1;
    }
};
