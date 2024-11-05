# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxDepth(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """

        def dfs(root, count):
            if root == None:
                return count
            else:
                count += 1
                count = max(dfs(root.left, count), dfs(root.right,count))
            return count  
        
        return dfs(root, 0)

# Argorithm: Depth First Search
        
        