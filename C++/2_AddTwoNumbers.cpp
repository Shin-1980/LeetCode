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

    int countNode(ListNode* l) {
        int num = 0;

        while (l != nullptr) {
            num++;
            l = l->next;
        }
        return num;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;  // carry over
        int val = 0;

        ListNode* head;
        ListNode* main;

        if (countNode(l1) < countNode(l2)) main = l2;
        else main = l1;

        head = main;

        while(l1 != nullptr || l2 != nullptr) {
            
            val = c;
            c = 0;

            if (l1 != nullptr) val += l1->val;
            if (l2 != nullptr) val += l2->val;
            if (val > 9) {
                val -= 10;
                c = 1;
            }

            main->val = val;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;

            if (l1 == nullptr && l2 == nullptr && c != 0) {
                ListNode* newNode = new ListNode(c);
                c = 0;
                main->next = newNode;
            }
            main = main->next;
        }

        return head;
    }
};

// 2,4,9
// 5,6
// 7,0,0,1