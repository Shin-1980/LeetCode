using namespace std;
#include <limits>
#include <algorithm>
#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct NodeInfo {
    TreeNode* node;
    int depth;
};
 
class Solution {
public:
    int searchCountWithDFS;
    int searchCountWithBFS;

    Solution() {
        this->searchCountWithDFS = 0;
        this->searchCountWithBFS = 0;
    }

    int minDepthWithDFS(TreeNode* root) {
        this->searchCountWithDFS++;
        if (root != nullptr) {
            if (root->left == nullptr && root->right == nullptr) return 1;

            int md = INT_MAX;
            if (root->left != nullptr) md = min(md, minDepthWithDFS(root->left)+1);
            if (root->right != nullptr) md = min(md, minDepthWithDFS(root->right)+1);

            return md;
        }

        return 0;
    }

    int minDepthWithBFS(TreeNode* root) {
        queue<NodeInfo> q;

        if (root == nullptr) return 0;

        TreeNode* cur = root;
        NodeInfo nodeInfo;
        nodeInfo.node = cur;
        nodeInfo.depth = 1;
        q.push(nodeInfo);

        while(!q.empty()){
            this->searchCountWithBFS++;

            auto cni = q.front();
            q.pop();
            if (cni.node->left == nullptr && cni.node->right == nullptr) return cni.depth;
            if (cni.node->left != nullptr) {
                cni.depth++;
                cni.node = cni.node->left;
                q.push(cni);
            }
            if (cni.node->right != nullptr) {
                cni.depth++;
                cni.node = cni.node->right;
                q.push(cni);
            }
        }
        
        return 0;
    }
};

void case1() {

    TreeNode* root = new TreeNode(3);
    TreeNode* l1_l = new TreeNode(9);
    TreeNode* l1_r = new TreeNode(20);
    TreeNode* l1_l2_l = new TreeNode(15);
    TreeNode* l1_l2_r = new TreeNode(7);
    
    root->left = l1_l;
    root->right = l1_r;
    l1_r->left = l1_l2_l;
    l1_r->right = l1_l2_r;

    Solution* sl = new Solution();
    int res = sl->minDepthWithDFS(root);
    cout << "DFS: The answer is " << res << ".   The number of recursive call is " << sl->searchCountWithDFS << endl;

    delete(root);
    delete(l1_l);
    delete(l1_r);
    delete(l1_l2_l);
    delete(l1_l2_r);
    delete(sl);

}

void case2() {

    TreeNode* root = new TreeNode(3);
    TreeNode* l1_l = new TreeNode(9);
    TreeNode* l1_r = new TreeNode(20);
    TreeNode* l1_l2_l = new TreeNode(15);
    TreeNode* l1_l2_r = new TreeNode(7);
    
    root->left = l1_l;
    root->right = l1_r;
    l1_r->left = l1_l2_l;
    l1_r->right = l1_l2_r;

    Solution* sl = new Solution();
    int res = sl->minDepthWithBFS(root);
    cout << "BFS: The answer is " << res << ".   The number of recursive call is " << sl->searchCountWithBFS << endl;

    delete(root);
    delete(l1_l);
    delete(l1_r);
    delete(l1_l2_l);
    delete(l1_l2_r);
    delete(sl);

}

int main() {

    case1();
    case2();

    return 0;
}