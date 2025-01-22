class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        
        num_freq = Counter(nums)
        min_heap = []

        for num, freg in num_freq.items():
            heappush(min_heap, (freg, num))

            if len(min_heap) > k:
                heappop(min_heap)

        top_k_freq = [pair[1] for pair in min_heap]

        return top_k_freq 
