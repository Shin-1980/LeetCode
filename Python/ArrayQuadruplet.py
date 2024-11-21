from typing import List

def find_array_quadruplet(arr: List[int], s: int) -> List[int]:
    arr.sort()

    for i in range(len(arr) - 3):
        for j in range(i+1,len(arr) - 2):
            sumTwo = arr[i] + arr[j]
            idxs = j + 1
            idxe = len(arr) - 1
            while idxs < idxe: 
                sumFour = sumTwo + arr[idxs] + arr[idxe]
                if sumFour == s: 
                    return [arr[i],arr[j],arr[idxs],arr[idxe]]
                elif sumFour > s: 
                    idxe -= 1
                else: 
                    idxs += 1
            
    
    return []

# [0,4,5,7,9]  pick up 0 and 4 by two pinters
# [5,9] current sum is 18, target sum is 20 -> smaller index should increment

