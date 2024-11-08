# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: Optional[ListNode]
        :type l2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """

        sul = ListNode(0) #sum list 
        head = sul

        cv = 0 # a value to carry over

        while l1 != None or l2 != None or cv != 0:
            su = cv
            cv = 0

            if l1 != None:
                su += l1.val
            if l2 != None:
                su += l2.val
            
            if su < 10:
                head.val = su
            else:
                head.val = su - 10
                cv = 1

            if l1 != None:
                l1 = l1.next
            if l2 != None:
                l2 = l2.next

            if l1 != None or l2 != None or cv != 0:    
                head.next = ListNode(0)
                head = head.next

        return sul
        
# algorithm: make new list carring over a value if an added result is over 10
# confirm the cases, such as inconsistent length, carrying over 1
