class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        
        ht = {}

        for num in nums:
            if num in ht:
                ht[num] += 1
            else:
                ht[num] = 1

        hp = []

        for key, value in ht.items():
            heappush(hp, (value, key))
            if len(hp) > k:
                heappop(hp)

        for e in hp:
            print(e)

        ans = []

        for e in hp:
            ans.append(e[1])

        return ans