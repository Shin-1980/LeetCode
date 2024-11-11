class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """

        def bt(s,idx,num,ts):   # ts is temporal strings
            if idx == len(s):   # base
                return num
            else:
                if s[idx] not in ts:
                    return bt(s,idx+1,num+1,ts+s[idx])
                else:
                    return num
            
        mres = 0

        for i in range(len(s)):
            mres = max(mres,bt(s,i,0,""))  
            
        return mres

# backtracking and memoization

