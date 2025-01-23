class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        hp = []

        for i in range(min(k, len(nums1))):
            heappush(hp, (nums1[i]+nums2[0], i, 0))

        ans = []

        while hp and len(ans) < k:
            _, i, j = heappop(hp)
            ans.append([nums1[i], nums2[j]])
            if j + 1 < len(nums2):
                heappush(hp, (nums1[i]+nums2[j+1],i,j+1))

        return ans
        