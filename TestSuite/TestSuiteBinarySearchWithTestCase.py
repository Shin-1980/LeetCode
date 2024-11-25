import BinarySearch

sl = BinarySearch.Solution()
suit = 0

# odd, even
arr = [0,1,2,3,4]

# mid
target = 2
expect = 2
suit += 1
if expect == sl.binarySearch(arr, target):
    print("pass",suit)
else:
    print("error",suit)

# edge
target = 0
expect = 0
suit += 1
if expect == sl.binarySearch(arr, target):
    print("pass",suit)
else:
    print("error",suit)

target = 4
expect = 4
suit += 1
if expect == sl.binarySearch(arr, target):
    print("pass",suit)
else:
    print("error",suit)

arr = [0,1,2,3,4,5]
target = 5
expect = 5
suit += 1
if expect == sl.binarySearch(arr, target):
    print("pass",suit)
else:
    print("error",suit)

# other
target = 1
expect = 1
suit += 1
if expect == sl.binarySearch(arr, target):
    print("pass",suit)
else:
    print("error",suit)

target = 3
expect = 3
suit += 1
if expect == sl.binarySearch(arr, target):
    print("pass",suit)
else:
    print("error",suit)

target = 4
expect = 4
suit += 1
if expect == sl.binarySearch(arr, target):
    print("pass",suit)
else:
    print("error",suit)

# out of space
target = 6
expect = -1
suit += 1
if expect == sl.binarySearch(arr, target):
    print("pass",suit)
else:
    print("error",suit)

target = -1
expect = -1
suit += 1
if expect == sl.binarySearch(arr, target):
    print("pass",suit)
else:
    print("error",suit)


arr = [0,1,2,2,4,5,6]
target = 2
expect = 2
suit += 1
if expect == sl.binarySearchMin(arr, target):
    print("pass",suit)
else:
    print("error",suit)

arr = [0,1,2,3,4,5]
target = 2
expect = 2
suit += 1
if expect == sl.binarySearchMin(arr, target):
    print("pass",suit)
else:
    print("error",suit)

#      0,1,2,3,4,5,6,7,8
arr = [0,1,2,2,2,3,3,7,8]
target = 3
expect = 5
suit += 1
if expect == sl.binarySearchMin(arr, target):
    print("pass",suit)
else:
    print("error",suit)

#      0,1,2,3,4,5,6,7,8
arr = [0,1,2,2,2,5,6,7,8]
target = 3
expect = 5
suit += 1
if expect == sl.binarySearchMin(arr, target):
    print("pass",suit)
else:
    print("error",suit)

#      0,1,2,3,4,5,6,7,8
arr = [0,1,2,2,2,3,3,7,8]
target = 3
expect = 6
suit += 1
if expect == sl.binarySearchMax(arr, target):
    print("pass",suit)
else:
    print("error",suit)

#      0,1,2,3,4,5,6,7,8,9,10,11
arr = [0,1,2,2,2,3,3,3,3,3,10,11]
target = 3
expect = 9
suit += 1
if expect == sl.binarySearchMax(arr, target):
    print("pass",suit)
else:
    print("error",suit)

