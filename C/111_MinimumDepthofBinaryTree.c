/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MIN(a,b) (((a) < (b)) ? (a) : (b))

int minDepth(struct TreeNode* root) {
    if (!root) return 0;

    if (root->left == NULL && root->right == NULL) return 1; // base case

    int l = INT_MAX;
    int r = INT_MAX;

    if (root->left) l = minDepth(root->left);
    if (root->right) r = minDepth(root->right);

    return MIN(l,r) + 1;
}

/*
The goal of this algorithm is to determin the minimum depth of a binary tree, defined as the shortest path from the root to the nearest leaf node. I use a depth-first approach to solve this.
In this approach, the searching algorithm starts at the root, and traverses the tree recursively. When it reaches a leaf node, which has no children, it starts counting the depth in reverse as it returns up the recursive stack. During this process, the algorithm keeps track of the minimum depth by comparing the depths of all paths.
This process continues until all nodes have been processed, and the shortest depth is returned as the final depth.
*/