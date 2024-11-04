class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """

        ht1 = {}    # key: nums1
        ht2 = {}    # key: nums2

        res = []

        for i in range(len(nums1)):
            if nums1[i] not in ht1:
                ht1[nums1[i]] = 0

        for i in range(len(nums2)):
            if nums2[i] not in ht2:
                ht2[nums2[i]] = 0

        for k in ht1:
            if k in ht2:
                res.append(k)

        return res
        
# nums1 x nums2
# time: O(MN)    M is a num of nums1, N is a num of nums2
# memory: O(M + N)

# store values into hash tables without values duplicated