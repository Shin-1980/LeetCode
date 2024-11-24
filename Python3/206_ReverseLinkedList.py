# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:

        if head == None or head.next == None:   return head     # base case
        else:
            newHead = self.reverseList(head.next)
            head.next.next = head
            head.next = None
            return newHead

# return the reversed list.
#       i
# 1,2,3,4,5
#
# i->next->next = i
# i->next = None
