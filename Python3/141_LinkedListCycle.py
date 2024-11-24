# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        fi = head
        si = head

        while si != None and si.next != None and si.next.next != None:
            fi = fi.next
            si = si.next.next
            if fi == si: return True

        return False

# determine if the linked list has a cycle in it.
# the range [0, 104]
#      ij
# 3,2,0,-4
