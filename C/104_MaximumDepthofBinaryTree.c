/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
   
    if (root == NULL) return 0;  // base case
    
    int res1 = maxDepth(root->left) + 1;
    int res2 = maxDepth(root->right) + 1;
    
    return (res1 > res2) ? res1 : res2;
}

/*
The goal of the problem is to determine the maximum depth of a binary tree, defined as the longest path from the root node to the leaf node. I use a depth-first search approach to solve this.
In this approach, the algorithm traverses the binary tree, from the root node to each leaf node. During the traversal, the depth of the current layer is tracked, and when a leaf node is reached, the depth is returned. Throughout this process, the maximum depth is updated by comparing the current depth with the maximum depth encountered so far.
*/
