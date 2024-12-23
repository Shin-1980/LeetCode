using namespace std;
#include <unordered_map>
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
    TreeNode* buildTreeRecur(vector<int> &preorder, unordered_map<int, int> &ht, int &preIndex, int s, int e) {
        if (s > e) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[preIndex]);
        preIndex++;

        int index = ht[preorder[preIndex - 1]];

        root->left = buildTreeRecur(preorder, ht, preIndex, s, index-1);
        root->right = buildTreeRecur(preorder, ht, preIndex, index+1, e);
        
        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> ht;
        int preIndex = 0;

        for (int i=0;i<inorder.size();i++) {
            ht[inorder[i]] = i;
        }

        return buildTreeRecur(preorder, ht, preIndex, 0, preorder.size()-1);

    }
};
