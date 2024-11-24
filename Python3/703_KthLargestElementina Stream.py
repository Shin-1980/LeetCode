class KthLargest:

    score = []
    k = 0

    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.score = []

        for num in nums:
            _ = self.add(num)

        return None

    def add(self, val: int) -> int:
        heappush(self.score, val)
        if len(self.score) > self.k:
            heappop(self.score)

        return self.score[0]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)

# returns the kth highest test score 
