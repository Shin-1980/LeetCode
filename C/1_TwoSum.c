/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* map = (int*)malloc(numsSize * sizeof(int));

    for (int i=0;i<numsSize;i++) map[i] = -1;

    for (int i=0;i<numsSize;i++) {
        int comp = target - nums[i];
        for (int j=0;j<i;j++) {
            if (comp == map[j]) {
                int* res = (int*)malloc(*returnSize * sizeof(int));
                res[0] = j;
                res[1] = i;
                free(map);
                return res;
            }
        }
        map[i] = nums[i];
    }

    *returnSize = 0;
    free(map);
    return NULL;    
}

/*
The goal of this algorithm is to find a pari of elements whose sum equals the target. To achieve this, I use a hash table data structure.
In this approach, the algorithm iterates through the array from the beginning. For each element, it checks whether the complement exists in the hash map. If the complement is found, the indices of the current element and its complemet are returned as the result. If not, the current element is added to the hash map, and the search continues.
*/