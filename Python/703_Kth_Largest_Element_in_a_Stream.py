class KthLargest(object):

    scores = []
    topK = 0

    def sort(self):
        i = len(self.scores) - 1

        while i >= 1 and self.scores[i-1] < self.scores[i]:
            self.scores[i-1], self.scores[i] = self.scores[i], self.scores[i-1]
            i -= 1

    def __init__(self, k, nums):
        """
        :type k: int
        :type nums: List[int]
        """

        self.topK = k
        self.scores = []

        for i in range(len(nums)):
            self.add(nums[i])

    def add(self, val):
        """
        :type val: int
        :rtype: int
        """

        if len(self.scores) < self.topK:
            self.scores.append(val)
            self.sort()
        else:
            if self.scores[self.topK - 1] < val:
                self.scores[self.topK - 1] = val
                self.sort()
                    
        print(self.scores)

        if len(self.scores) < self.topK:
            return None

        return self.scores[self.topK - 1]

# data structure: arry
# search algorithm: babble sort
# time O(N logN)    N is a number of students
# memory O(k)



# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)