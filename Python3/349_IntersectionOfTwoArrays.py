class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        
        ht1 = {}
        ht2 = {}

        for num in nums1:
            if num not in ht1:
                ht1[num] = 0
        
        for num in nums2:
            if num not in ht2:
                ht2[num] = 0

        ans = []

        for num in ht1:
            if num in ht2:
                ans.append(num)

        return ans

