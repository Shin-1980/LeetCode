# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        
        fi = head   # faset index
        si = head   # slow index

        while True:
            
            if si == None or si.next == None:
                return False

            fi = fi.next
            si = si.next.next

            if fi == si:
                return True

        return False

# two pointers
# time: O(N)    N is num of node.       N / 2
# memory: O(N)

# if next node is null -> false
# check address not value
