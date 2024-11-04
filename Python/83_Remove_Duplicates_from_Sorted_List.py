# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """

        i = head   # index

        while i.next != None:
            if i.val == i.next.val:
                i.next = i.next.next
            else:
                i = i.next

        return head
        
# check a value at the next node
# if the next value is same as the current: link to next next node.
# if not same: go to the next node.
