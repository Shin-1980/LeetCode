# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[List[int]]
        """

        que = []

        if root == None:
            return []

        que.append(root)
        values = []
        res = []

        while len(que) > 0:

            for i in range(len(que)):
                node = que.pop(0)
                if node != None:
                    values.append(node.val)
    
                if node != None:
                    if node.left != None:
                        que.append(node.left)
                    if node.right != None:
                        que.append(node.right)

            res.append(values)
            values = []

        return res

# Algorithm: BSF
# store nodes in each depth
# exceptional case: root is none        