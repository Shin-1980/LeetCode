# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def minDepth(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """

        def dfs(root,count):
            if root != None and root.left == None and root.right == None:    # base
                print(root.val,count)
                return count
            else:
                count += 1
                if root != None:
                    #print(root.val)
                    if root.left == None:
                        count = dfs(root.right,count)
                    elif root.right == None:
                        count = dfs(root.left,count)
                    else:
                        count = min(dfs(root.left,count), dfs(root.right,count))    
            return count

        return dfs(root, 1)

# algorithm: depth first search
# return min depth
        