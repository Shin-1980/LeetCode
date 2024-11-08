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

        preh = ListNode(-1,head)
        cur = preh

        while cur != None and cur.next != None and cur.next.next != None:
            if cur.next.val != cur.next.next.val:
                cur = cur.next
            else:
                nxt = cur.next
                while nxt != None and nxt.next != None:
                    if nxt.val != nxt.next.val:
                        break

                    nxt = nxt.next
                cur.next = nxt.next

        return preh.next


# check cur and next, if they are duplicated skip until node having different value # points: head and tail
        