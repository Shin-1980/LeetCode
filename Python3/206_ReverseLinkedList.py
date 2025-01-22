class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:

        if not head:
            return head

        st = []
        cur = head

        while cur != None:
            st.append(cur)
            cur = cur.next

        newHead = st.pop()
        cur = newHead

        while len(st) > 0:
            l = st.pop()
            cur.next = l
            cur = cur.next

        cur.next = None

        return newHead