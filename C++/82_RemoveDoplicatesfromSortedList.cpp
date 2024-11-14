/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode phead = ListNode(0,head);
        ListNode* cur = &phead;

        while (cur != NULL && cur->next != NULL && cur->next->next != NULL) {
            if (cur->next->val != cur->next->next->val){
                cur = cur->next;
            }
            else {
                while (cur->next != NULL && cur->next->next != NULL) {
                    if (cur->next->val != cur->next->next->val) {
                        break;
                    }
                    cur->next = cur->next->next;
                }
                cur->next = cur->next->next;
            }
        }

        return phead.next;
    }
};


// pointer
// optimization
// memories 
//  prehead: a memory to skip head if head is duplicated
// pointers
//  pre, cur, nxt
// condition
//  if vals of cur and nxt are not same, shift all pointers
//  if same, skip until vals of nxt and nxtnxt are not same 

// exception
// head = []
// head = [1,1]
