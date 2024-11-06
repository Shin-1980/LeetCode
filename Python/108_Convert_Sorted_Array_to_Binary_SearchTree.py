# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: Optional[TreeNode]
        """

        def dfs(nums, idxs, idxe, res):
            print(idxs,idxe)
            if idxs == idxe: # base
                res.val = nums[idxs]
                return

            dif = idxe - idxs
            if dif > 1:
                idxm = dif // 2 + idxs
                if res != None:
                    res.val = nums[idxm]
                    if (idxm - 1) - idxs >= 1:
                        res.left = TreeNode()
                        dfs(nums, idxs, (idxm-1), res.left)
                    if idxe - (idxm + 1) >= 1:
                        res.right = TreeNode()
                        dfs(nums, (idxm+1), idxe, res.right)
            else:
                res.val = nums[idxe]
                res.left = TreeNode()
                dfs(nums, idxs, idxe - 1, res.left)
            
            return
        
        res = TreeNode()
        dfs(nums, 0, len(nums) - 1, res)

        return res


    
# algorithm: find a middle array which can be root in each layer
# if num of array is less than 2, a bigger value becomes root in each layer
# use index and recursive function, maintain        