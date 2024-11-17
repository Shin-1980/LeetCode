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
The goal of the problem is to return the array such that all 0 are moved to the end of the array. 
I use a pointer to solve this issu.
In this approach, the algorithm iterates through the array from the beginning to the end. During this process, the algorithm counts the number of zero. If the element is not zero, this element is copied to the left side of the array in order.
*/
