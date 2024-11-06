# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    res = False

    def hasPathSum(self, root, targetSum):
        """
        :type root: Optional[TreeNode]
        :type targetSum: int
        :rtype: bool
        """

        def dfs(root, targetSum, curSum):
            if root == None:    # base
                if targetSum == curSum:  # base
                    self.res = True
                return

            curSum += root.val
            dfs(root.left, targetSum, curSum)
            dfs(root.right, targetSum, curSum)

            return

        if root != None:
            dfs(root, targetSum, 0)
        
        return self.res

# algorithm: DFS
# how to notice to detect a combination  
# time O(N) N is num of node
# memory O(N) 
