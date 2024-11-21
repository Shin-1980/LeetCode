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
    TreeNode* bnSearch(vector<int>& nums, int s, int e) {
        if (s > e) return NULL;
        else {
            int m = (e + s) / 2;
            TreeNode* newN = new TreeNode(nums[m],bnSearch(nums,s,m-1),bnSearch(nums,m+1,e));
            return newN;
        }
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bnSearch(nums,0,nums.size()-1);
    }
};

