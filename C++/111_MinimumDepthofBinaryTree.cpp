using namespace std;
#include <climits>

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
    int minDepth(TreeNode* root) {
        if (root != nullptr) {
            if (root->left == nullptr && root->right == nullptr) return 1;

            int md = INT_MAX;
            if (root->left != nullptr) md = min(md, minDepth(root->left)+1);
            if (root->right != nullptr) md = min(md, minDepth(root->right)+1);

            return md;
        }

        return 0;
    }
};