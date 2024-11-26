#include <iostream>

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode pre(0,head);
        ListNode* cur = &pre;

        // {1,1,2,3,3,4,4,5};
        //(0)  (2),       

        while (cur != NULL && cur->next != NULL && cur->next->next != NULL) {
            if (cur->next->val != cur->next->next->val) {
                cur = cur->next;
            }
            else{
                while (cur->next != NULL && cur->next->next != NULL) {
                    if (cur->next->val != cur->next->next->val) {
                        //cur->next = cur->next->next;
                        break;
                    }
                    cur->next = cur->next->next;
                }
                cur->next = cur->next->next;
            }
        }

        return pre.next;
    }

// 1, 2, 3, 4, 5
// 1  2
// copy
// change link

    ListNode* reverseList(ListNode* head) {

        if (head == NULL || head->next == NULL) return head;
        else{
            ListNode* newHead = reverseList(head->next);
            head->next->next = head;
            head->next = NULL;
            return newHead;
        } 

        return head;
    }
};



bool testSuite1(int testCase) {

    const int listNum = 8;//sizeof(arr);
    Solution slt;
    ListNode ln[listNum];

    int arr[5] = {1,2,3,4,5};

    //std::cout << std::size(arr) << std::endl;

    for (int i=0;i<listNum;i++) {
        ln[i].val = arr[i];
    }
    for (int i=0;i<listNum-1;i++) {
        ln[i].next = &ln[i+1];
    }

    ListNode* head = &ln[0];
    ListNode* res = slt.deleteDuplicates(head);

    //int ans[2] = {2,5};
    int ans[5] = {1,2,3,4,5};

    //std::cout << sizeof(arr) << std::endl;    

    for( auto a : ans) {
        if (a != res->val) {
            return false;
        }
        res = res->next;  
    }

    return true;
    
}

bool testSuite2(int testCase) {

    const int listNum = 5;
    Solution slt;
    ListNode ln[listNum];

    int arr[5] = {1,2,3,4,5};

    for (int i=0;i<listNum;i++) {
        ln[i].val = arr[i];
    }
    for (int i=0;i<listNum-1;i++) {
        ln[i].next = &ln[i+1];
    }

    ListNode* head = &ln[0];
    ListNode* res = slt.reverseList(head);

    int ans[5] = {5,4,3,2,1};

    //std::cout << sizeof(arr) << std::endl;    

    for( auto a : ans) {
        if (a != res->val) {
            return false;
        }
        res = res->next;  
    }

    return true;
}

int main()
{
    int testCase = 1;
    if (testSuite1(testCase)) {
        std::cout << "PATH:" << testCase << std::endl;         
    }
    else {
        std::cout << "ERROR:" << testCase << std::endl;         
    }
    testCase++;

    if (testSuite2(testCase)) {
        std::cout << "PATH:" << testCase << std::endl;         
    }
    else {
        std::cout << "ERROR:" << testCase << std::endl;         
    }
    testCase++;



}

