class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        if len(s) != len(t):
            return False
        
        if len(s) == 0:
            return False

        counters = [0 for _ in range(ord('z') - ord('a') + 1)]

        for c in s:
            counters[ord(c) - ord('a')] += 1

        for c in t:
            counters[ord(c) - ord('a')] -= 1

        for counter in counters:
            if counter != 0:
                return False

        return True
