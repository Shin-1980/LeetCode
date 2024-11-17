void moveZeroes(int* nums, int numsSize) {
    int cz = 0;     // count zero
    int idx = 0;    

    for (int i=0;i<numsSize;i++) {
        if (nums[i] != 0) {
            nums[idx++] = nums[i];
        }
        else cz++;
    }  

    for (int i=0;i<cz;i++) {
        nums[numsSize-1-i] = 0;
    }
}

/*
The goal of the problem is to modify the array such that all the zeros are moved to the end while maintaining the relative order of the non-zero elements.
I use a pointer-based approach to solve this issu.
In this approach, the algorithm iterates through the array from the beginning to the end. 
During the iteration, the algorithm keeps track of the count of zeroes. 
For each non-zero element encountered, the element is copied to the left side of the array in order. 
This ensures that all-non-zero elements are shifted to the front, leaving space for the zeroes at the end.
*/

