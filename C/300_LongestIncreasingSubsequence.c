int btLIS(int* nums, int numsSize, int curIdx, int* memo) {
    if (numsSize == curIdx) return 0;  // base case

    if (memo[curIdx] != -1) return memo[curIdx];

    int mx = 1;
    for (int prev = 0; prev < curIdx; prev++) {
        if (nums[prev] < nums[curIdx]) {
            int current = btLIS(nums, numsSize, prev, memo) + 1;
            if (current > mx)
                mx = current;
        }
    }

    memo[curIdx] = mx;

    return mx;
}

int lengthOfLIS(int* nums, int numsSize) {
    int memo[numsSize];

    for (int i=0;i<numsSize;i++){
        memo[i] = -1;
    }

    int max = 1;

    for (int i=1;i<numsSize;i++){
        int lgt = btLIS(nums, numsSize, i, memo);
        if (max < lgt) max = lgt;
    }

    return max;
}

/*
The goal of this algorithm is to find the longest subsequence of increasing elements while preserving their original order in the array. 
I use a backtracking approach to solve this problem.
In this approach, the algorithm traverses the array from the beginning to the end, tracking the length of the subsequence along the way. 
If the next elements is larger than the current elements, the subsequence length is incremented. Otherwise, the algorithm continues to the next element without updating the length. 
To explore all possible combinations of subsequences, the search starts from each element in the array.
*/