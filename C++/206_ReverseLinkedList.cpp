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
    ListNode* reverseList(ListNode* head) {
        
        if (head == NULL){
            return head;
        }

        stack<int> st;     // stack
        ListNode* cur = head;

        while (cur != NULL) {
            st.push(cur->val);
            cur = cur->next;
        }

       cur = head;

        while (cur != NULL) {
            cur->val = st.top();
            st.pop();
            cur = cur->next;
        }

        return head;
    }
};

// stack
// time O(N)    N is the length of list
// memory O(N)
        
