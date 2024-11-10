# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[List[int]]
        """

        if root == None:
            return []

        que = []
        values = []
        res = []

        que.append(root)
        depth = 1

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

            if depth % 2 == 0:
                values.reverse()

            res.append(values)
            
            values = []
            depth += 1

        return res



        
# Algorithm: BFS 
# store values in each level
# exceptironal case: root is none