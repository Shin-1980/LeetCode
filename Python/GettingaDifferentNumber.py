from typing import List

def get_different_number(arr: List[int]) -> int:

    arr.sort()

    for i in range(len(arr)):
        if i != arr[i]:
            return i

    return len(arr)

