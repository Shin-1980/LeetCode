#define MAX(a,b) ((a > b) ? a : b)

int maxSubArray(int* nums, int numsSize) {
    int curSum = 0;
    int endSum = INT_MIN;

    for (int i=0;i<numsSize;i++) {
        curSum = MAX(nums[i], curSum + nums[i]);
        endSum = MAX(endSum, curSum);
    }

    return endSum;
}

/*
The goal of this problem is to determined the largest sum calculated by the sum of subarray. 
I use a memoization approach, commonly reffered to as Kadane's Algorithm.
In this approach, the algorithm iterates the array from the beginning to the end. 
During this process, two values are tracked: 
the current maximum sum, which is representing the largest sum ending at the current position, 
and the global maximum sum, which is representing the largest sum encountered so far.
The current maximum sum is updated at each step by comparing the current element itself and the sum of the current element with the previous maximum sum. 
The global maximum sum is updated whenever the current maximum sum exceeds its stored value.
At the end of the iteration, the global maximum sum is returned as the result.
*/