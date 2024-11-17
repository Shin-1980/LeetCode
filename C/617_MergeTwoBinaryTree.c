/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) {

    if (!root1) return root2;
    if (!root2) return root1;

    root1->val += root2->val;

    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);

    return root1;
}

/*
The goal of this problem is to mearge two binary trees. I use a depth-first search apporach to achieve this.
In this approach, the merging process starts at the root nodes of the two trees and proceeds recursively to each leaf node. The value of root1 is updated by adding the correspoiding value of root2. This process continues until all node in both trees are processed. If a branch of root1 is null but the corresponding branch of root2 is not null, the subtree of root2 is attached to root 1 by updating the pointer from root1 to root2.
An alternative approach is to use a breadth-first search approach. However, this approach is more challenging because it requires maintaining additional information to track correspoinding nodes in both trees during traversal.
*/
