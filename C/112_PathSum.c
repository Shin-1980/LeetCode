/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool dfs(struct TreeNode* root, int targetSum, int curSum) {
    if (root == NULL) return false; // base case
    int sum = curSum+root->val;
    if (root->left == NULL && root->right == NULL && targetSum == sum) return true;

    bool ans1 = dfs(root->left, targetSum, sum);
    bool ans2 = dfs(root->right, targetSum, sum);
    return ans1 || ans2;
}

bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) return false;

    return dfs(root, targetSum, 0);
}

/*
The goal of this problem is to determine whether a given binary tree has a root-to-leaf path such that sum of the node values along the path equals the target sum. To solve this, I use depth-first search approach.
In this approach, the total value of each path is calculated recursively as the algorithm traverses the tree from to each leaf. If any root-to-leaf path results in a sum that maches the target sum, the function returns true. If all path are evaluated and none match the target sum, the function returns false.
*/