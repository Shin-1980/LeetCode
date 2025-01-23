class Solution:
    def firstUniqChar(self, s: str) -> int:
        
        ht = {}

        for c in s:
            if c in ht:
                ht[c] += 1
            else:
                ht[c] = 1

        for i in range(len(s)):
            if ht[s[i]] == 1:
                return i

        return -1 
            