/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare (const void * a, const void * b) 
{
   return ( *(int*)a - *(int*)b ); 
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    qsort(nums1, nums1Size, sizeof(int), compare);    
    qsort(nums2, nums2Size, sizeof(int), compare);

    int* map1 = (int*)malloc(sizeof(int)*nums1Size);
    int* map2 = (int*)malloc(sizeof(int)*nums2Size);

    map1[0] = nums1[0];
    map2[0] = nums2[0];

    int idxMap1 = 1;
    int idxMap2 = 1;

    for (int i=1;i<nums1Size;i++) {
        if (nums1[i-1] != nums1[i]) map1[idxMap1++] = nums1[i];
    }

    for (int i=1;i<nums2Size;i++) {
        if (nums2[i-1] != nums2[i]) map2[idxMap2++] = nums2[i];
    }

    int idx1 = 0;
    int idx2 = 0;

    int resNum = (idxMap1 > idxMap2)? idxMap1: idxMap2;

    printf("%d",resNum);

    int* res = (int*)malloc(sizeof(int)*resNum);
    *returnSize = 0;

    while (idx1<idxMap1 && idx2<idxMap2) {
        if (map1[idx1] == map2[idx2]) {
            res[(*returnSize)++] = map1[idx1];
            idx1++;
            idx2++;
        }
        else if (map1[idx1] < map2[idx2]) {
            idx1++;
        }
        else{
            idx2++;
        }
    }

    return res;
}

/*
The goal of this algorithm is to find intersection of two arrays, returning the unique elements that appear in both arrays. To address this, I use a sorting algorithm and a hash table.

In this approach, both arrays are first sorted in ascending order. A hash table is used to store unique elements from one of the arrays for quick lookups. Two pointers are then used to traverse the sorted arrays. If two elements at the two pointers are the same, the element is added to the result set. If the elements differ, the pointer for the smaller element is incremented. This process continues until one of the pointers reaches the end of its array.
*/