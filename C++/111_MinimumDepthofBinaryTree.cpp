/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return NULL;
        if(root != NULL && root->left == NULL && root->right == NULL) return 1;
        else {
            int mn = INT_MAX;
            if (root->left != NULL) mn = min(mn, minDepth(root->left));
            if (root->right != NULL) mn = min(mn, minDepth(root->right));

            return mn + 1;
        }
    }
};