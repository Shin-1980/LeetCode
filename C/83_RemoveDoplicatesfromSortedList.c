/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* cp;    // current pointer
    cp = head;

    while (cp != NULL && cp->next != NULL) {
        if (cp->val != cp->next->val) cp = cp->next;
        else cp->next = cp->next->next;
    }

    return head;
}

/*
The goal of this algorithm is to return a list with all duplicate values removed. To achieve this, I use a poinerbased approachto determine whether the neighboring nodes have the same value.
In this approach, the pointer traverse the list until reaches the end. If the value of the current node is equal to the value of the next node, the pinter of the current node is updated to skip the duplicate by pointing to the node after the next. Otherwise, the pointer simply moves to the next node.
*/