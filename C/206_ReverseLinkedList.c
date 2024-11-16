/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    struct ListNode* newh = reverseList(head->next);
    //head->next = head;
    head->next->next = head;
    head->next = NULL;
    return newh;
}

/*
The goal of this problem is to reverse a linked list. I use a recursive approach to change the direction of the list. 

In this approach, revursive calls are made until the end of the list is reached. Each call processes one node at a time, storing the previous node and, while returning back through the recursive stack, updates the direction of the pointers to revere the list.

One tricky part is identifying and returning the new head of the reversed list. To handle this, I use the return value of the revursive function to pass back the new head node.
Another challenge is ensuring the list terminates correctly. This is achieved by updating the next pointer of the current node to null when necessary during the recursion.
*/