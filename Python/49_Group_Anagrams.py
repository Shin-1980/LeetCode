class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """

        cach = []
        for i in range(len(strs)):
            st = ''.join(sorted(strs[i]))
            cach.append(st)

        print(cach)
        ht = {}     # store index already searched
        res = []

        for i in range(len(cach)):
            if i not in ht:                
                comb = [strs[i]]
                for j in range(i+1,len(cach)):
                    if cach[i] == cach[j] and j not in ht:
                        comb.append(strs[j])
                        ht[j] = 0
                res.append(comb)

        return res

# character count
# time O(N*M)
# memory O(N*M)
