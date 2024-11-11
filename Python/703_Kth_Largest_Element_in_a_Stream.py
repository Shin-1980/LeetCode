class KthLargest(object):

    scores = []
    k = 0

    def __init__(self, k, nums):
        """
        :type k: int
        :type nums: List[int]
        """

        self.k = k
        self.scores = []

        for num in nums:
            self.add(num)

    def add(self, val):
        """
        :type val: int
        :rtype: int
        """

        heappush(self.scores, val)
        if len(self.scores) > self.k:
            heappop(self.scores)

        return self.scores[0]

# data structure: heapqueue
# time O(N logN)    N is a number of students
# memory O(k)

# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)