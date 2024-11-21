class Solution {
public:
    int firstUniqChar(string s) {
        
        int counters[26];

        for (auto counter: counters) counter = 0;
        
        for (auto c: s) {
            int idx = c - 'a';
            cout << idx << endl;
            counters[idx]++;
        }

        int idxArray = 0;
        for (auto c: s) {
            int idx = c - 'a';
            if (counters[idx] == 1) return idxArray;
            idxArray++;
        }

        return -1;
        
    }
};
