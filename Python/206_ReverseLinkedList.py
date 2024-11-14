# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseList(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """

        st = []     #stack
        cur = head

        while cur != None:
            st.append(cur.val)
            cur = cur.next

        cur = head
        while cur != None:
            cur.val = st.pop(len(st)-1)
            cur = cur.next

        return head
        
        