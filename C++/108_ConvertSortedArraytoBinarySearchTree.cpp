using namespace std;
#include <vector>

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
    void makeTree(vector<int>& nums, TreeNode*& root, int l, int r) {
        if (l > r) return;

        int m = (r+l) / 2;
        root = new TreeNode(nums[m]);

        makeTree(nums, root->left, l, m-1);
        makeTree(nums, root->right, m+1, r);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root;
        makeTree(nums, root, 0, nums.size()-1);
        
        return root;
    }
};

