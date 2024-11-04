# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    res = None
    next = None

    def reverseList(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """

        def rf(head):
            node = head

            if head != None and head.next == None:    # base
                self.res = ListNode(head.val)
                self.next = self.res
                return
            else:
                if head != None:
                    rf(head.next)

                if node != None:
                    newNode = ListNode(node.val)
                    self.next.next = newNode
                    self.next = self.next.next

            return

        rf(head)
        return self.res
        

# recursive function
# time: O(N)    N is a number of nodes
# memory: O(N) 
# advantage: no additional memory
