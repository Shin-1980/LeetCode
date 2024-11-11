/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode *fp = head;    // fast pointer    
        ListNode *sp = head;    // slow pointer

        while (fp != NULL and fp->next != NULL) {
            fp = fp->next->next;
            sp = sp->next;

            if (fp == sp) {
                return true;
            }
        }

        return false;
    }
};