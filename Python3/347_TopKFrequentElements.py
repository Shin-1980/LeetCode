class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        
        ht = {}

        for num in nums:
            if num not in ht:
                ht[num] = 1
            else:
                ht[num] += 1

        min_heap = []

        for key, val in ht.items():
            heappush(min_heap, (val, key))

            if len(min_heap) > k:
                heappop(min_heap)

        top_k_freq = [pair[1] for pair in min_heap]

        return top_k_freq 
