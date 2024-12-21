using namespace std;
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answers;
        vector<int> ans;
        queue<TreeNode*> q;

        if (!root) return {};
        q.push(root);

        while(!q.empty()){
            int count = q.size();

            for(size_t i=0;i<count;i++) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur) {
                    ans.push_back(cur->val);
                    if (cur->left) q.push(cur->left);
                    if (cur->right) q.push(cur->right);
                }
            }

            answers.push_back(ans);
            while(!ans.empty()) ans.pop_back();

        }

        return answers;        
    }
};