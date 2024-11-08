# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """

        fstn = head   # fast node: 2 step
        slwn = head   # slow node: 1 steps

        while fstn != None and fstn.next != None:
            fstn = fstn.next.next
            slwn = slwn.next
            #print(fstn.val, slwn.val)

            if fstn == slwn:
                fstn = head

                while fstn != slwn:
                    print(fstn.val, slwn.val)

                    fstn = fstn.next
                    slwn = slwn.next

                return fstn
            
        return None
                    
# two pointers:  1step and 2 steps
# if meet two pointers each other, it's cycler link
# if not, it's not cycler link

        