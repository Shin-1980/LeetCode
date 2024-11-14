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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* pre = new ListNode();
        ListNode* l3 = pre;

        int co = 0;     // carry over
        int val = 0;

        while (l1 != NULL || l2 != NULL || co != 0) {
            val = co;
            co = 0;
            
            if (l1 != NULL){
                val += l1->val;
                l1 = l1->next; 
            } 
            if (l2 != NULL){
                val += l2->val;
                l2 = l2->next;
            } 

            if (val > 9) {
                val -= 10;
                co = 1;
            }

            l3->next = new ListNode(val);
            l3 = l3->next;
            
        }

        return pre->next;

    }

};

// algorithm linked list + memoty to carry over