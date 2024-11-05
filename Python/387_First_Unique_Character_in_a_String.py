class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """

        ht = {} # key: str, value: number to appear

        for i in range(len(s)):
            if s[i] not in ht:
                ht[s[i]] = 1
            else:
                ht[s[i]] += 1

        for i in range(len(s)):
            if ht[s[i]] == 1:
                return i

        return -1

# use hashtable to count the number of occurence the same character
# time O(N^2)   N is length of the string
# memory O(N)
        
        