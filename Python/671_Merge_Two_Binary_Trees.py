# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def mergeTrees(self, root1, root2):
        """
        :type root1: Optional[TreeNode]
        :type root2: Optional[TreeNode]
        :rtype: Optional[TreeNode]
        """

        def dfs(root1,root2,res):
            if root1 == None and root2 == None and res == None: # base
                return
            else:
                res.val = 0
                if root1 != None:
                    res.val += root1.val
                if root2 != None:
                    res.val += root2.val

                if (root1 != None and root1.left != None) or (root2 != None and root2.left != None):
                    res.left = TreeNode()
                    dfs(root1.left, root2.left, res.left)
                if (root1 != None and root1.right != None) or (root2 != None and root2.right != None):
                    res.right = TreeNode()
                    dfs(root1.right, root2.right, res.right)
                
            return

        res = TreeNode(root1.val+root2.val)
        dfs(root1,root2,res)
                
        return res

# algorithm DFS: it can maintain correspondence between root1 and root2 without extra memory
# time: O(N)       N is num of array which a larger value between root1 and root2 including null
# memory: O(N) 
