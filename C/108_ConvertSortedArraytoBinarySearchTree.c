/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* createNode(int num) {
    struct TreeNode* newTr = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newTr->val = num;
    newTr->left = NULL;
    newTr->right = NULL;

    return newTr;
}

struct TreeNode* sortedArray(int* nums, int start, int end) {
    if (start > end) return NULL;

    int mid = (start + end) / 2;
    struct TreeNode* newTr = createNode(nums[mid]);

    newTr->left = sortedArray(nums, start, mid-1);
    newTr->right = sortedArray(nums, mid+1, end);

    return newTr;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return sortedArray(nums, 0, numsSize-1);
}

/*
The goal of this problem is to conver an array to height-balanced binary search tree. 
To solve this, I use a binary search approach to find the middle element of the array,
which serves as the root node at each level of the tree.
In this approach, the binary search is applied recursively until all elements in the array are processed. 
If the number of the elements in the current subarray is zero, the function returns null. 
Otherwise, a new node is created with the middele element as its value. 
Two recursive calls are then made to process the left and right halves of the array, 
and thier return values are assigned to the left and right child nodes of the current root, respectively. 
*/
