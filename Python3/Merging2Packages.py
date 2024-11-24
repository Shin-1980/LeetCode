from typing import List

def get_indices_of_item_weights(arr: List[int], limit: int) -> List[int]:
    ht = {}     # value:idx

    #for i, num in enumerate(arr):
    for i in range(len(arr)-1,-1,-1):
        comp = limit - arr[i]   
        if comp in ht:
            return [ht[comp],i]
        else:
            ht[arr[i]] = i

    return []


arr = [4, 4, 1]
lim = 5
print(get_indices_of_item_weights(arr,lim))

