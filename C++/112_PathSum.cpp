using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}; 

class Solution {
public:
    bool calDum(TreeNode* root, int targetSum, int curSum) {
        if (root!=nullptr){
            if (root->left==nullptr && root->right==nullptr) {
                if (targetSum == curSum + root->val) return true;
            }
        
            curSum += root->val;        
            return (calDum(root->left,targetSum,curSum) || calDum(root->right,targetSum,curSum));
        }
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return calDum(root, targetSum, 0);
    }
};