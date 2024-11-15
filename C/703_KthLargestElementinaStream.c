


typedef struct {
    int k;
    int count;
    int* nums   // ascending order
} KthLargest;

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* kl = (KthLargest*)malloc(sizeof(KthLargest));

    kl->k = k;
    kl->count = 0;
    //kl->nums = (int *)calloc(k, sizeof(int));
    kl->nums = (int *)malloc(k * sizeof(int));
    if (kl->nums == NULL) return NULL;

    for (int i=0;i<k;i++) {
        kl->nums[i] = pow(10,4) * -1;
    }

    for (int i=0;i<numsSize;i++){
        int res = kthLargestAdd(kl, nums[i]);
    }

    return kl;
}

int kthLargestAdd(KthLargest* obj, int val) {
    
    if (obj->nums[0] < val) {
        obj->nums[0] = val;        
        heap(obj->nums, obj->k);
    }

    return obj->nums[0];   
}

void heap(int* nums, int numsSize){
    for(int i=0;i<numsSize-1;i++){
        if (nums[i] > nums[i+1]){
            int tmp = nums[i];
            nums[i] = nums[i+1];
            nums[i+1] = tmp;
        }
        else{
            break;
        }
    }
}

void kthLargestFree(KthLargest* obj) {
    free(obj);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 
 * kthLargestFree(obj);
*/