# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    
    def isValidBST(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """

        def dfs(root):
            if root == None:# base
                return True
            else:
                res = True
                if root.left != None:
                    if root.left.val < root.val:
                        res = dfs(root.left)
                    else:
                        return False

                if root.right != None:
                    if root.val < root.right.val:
                        res = dfs(root.right)
                    else:
                        return False
            
            return res

        return dfs(root)
        
# algorithm DFS
# condition: light < root < right
# time O(N) N is number of nodes
# memory O(N) 