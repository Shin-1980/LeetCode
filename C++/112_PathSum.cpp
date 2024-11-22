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
private:
    bool dfs(TreeNode* root, int targetSum, int curSum) {
        if (root == NULL) return 0; // base node
        else if(root->left == NULL && root->right == NULL){
            if (targetSum == curSum + root->val) return true;
        }
        else {
            bool res = false;
            res |= dfs(root->left, targetSum, curSum + root->val);
            res |= dfs(root->right, targetSum, curSum + root->val);
            return res;
        }
        return false;
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        else return dfs(root,targetSum,0);
    }
};