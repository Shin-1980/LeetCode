class Solution(object):
    def kSmallestPairs(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[List[int]]
        """

        mn1 = len(nums1)    # max num of nums1
        mn2 = len(nums2)    # max num of nums2

        res = [[nums1[0], nums2[0]]]

        n1 = 0
        n2 = 0

        for i in range(1,k):
            res1 = res2 = 0
            if n1+1 < mn1:
                res1 = nums1[n1+1] + nums2[n2]
            if n2+1 < mn2:
                res2 = nums1[n1] + nums2[n2+1]

            if res1 < res2:
                pair = [nums1[n1+1], nums2[n2]]
                res.append(pair)
                n1 += 1
            else:
                pair = [nums1[n1], nums2[n2+1]]
                res.append(pair)
                n2 += 1

        return res
            
        
# algorithm: two pointers
