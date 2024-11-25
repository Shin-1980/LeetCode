class Solution:
    def binarySearch(self, arr: list[int], target: int) -> int:
        s = 0
        e = len(arr) - 1

        while s<=e:
            m = (s + e) // 2
            if target == arr[m]:
                return m
            elif target < arr[m]:
                e = m - 1
            else:
                s = m + 1

        return -1

    def binarySearchMin(self, arr: list[int], target: int) -> int:
        s = 0
        e = len(arr) - 1

        while s<=e:
            m = (s + e) // 2
            if target <= arr[m]:
                e = m - 1
            else:
                s = m + 1

        return s


#       0,1,2,3,4,5,6,7,8
#arr = [0,1,2,2,2,3,3,7,8]
#target = 3
#m -> 

    def binarySearchMax(self, arr: list[int], target: int) -> int:
        s = 0
        e = len(arr) - 1

        while s<=e:
            m = (s + e) // 2
            if target < arr[m]:
                e = m - 1
            else:
                s = m + 1

        return e
