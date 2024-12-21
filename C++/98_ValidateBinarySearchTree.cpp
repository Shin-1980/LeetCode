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
    bool isValidBSTwithMinMax(TreeNode* root, long long min, long long max){
        if (!root) return true;
        else{
            if (min >= root->val || root->val >= max) return false; 

            return (isValidBSTwithMinMax(root->left, min, root->val) 
            && isValidBSTwithMinMax(root->right, root->val, max));
        }
    }

    bool isValidBST(TreeNode* root) {
        return isValidBSTwithMinMax(root, LLONG_MIN, LLONG_MAX);
    }

};