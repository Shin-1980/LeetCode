/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode* fp;    // a faster pointer
    struct ListNode* sp;    // a slower pointer

    fp = head;
    sp = head;

    if (head == NULL) return false;

    while (sp->next != NULL && sp->next->next != NULL) {
        fp = fp->next;
        sp = sp->next->next;
        if (fp == sp) return true;
    }

    return false;
}

/*
The goal of this problem is to determine whether a linked list contains a cycle. 
To solve this issue, I use two-pointer technique, also known as the fast and slow pointer approach.

In this method, two pointers traverse the linked list at different speeds: 
the fast pointer moves two steps at a time, while the slow pointer move one step at a time. 
If the fast pointer and the slow pointer meet at any point during the traversal, it indicate that the linked list has a cycle. Conversely, if the fast poiner reaches the end of the linked list, it confirms that the linked list does not contain a cycle.
*/
