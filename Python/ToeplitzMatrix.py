from typing import List

def isToeplitz(arr: List[List[int]]) -> bool:
    mr = len(arr)       # max row
    mc = len(arr[0])    # max col
    
    for r in range(mr-1):
        for c in range(mc-1):
            #print(r,c)
            if arr[r][c] != arr[r+1][c+1]:
                return False

    return True

# i,j = i+1,j+1