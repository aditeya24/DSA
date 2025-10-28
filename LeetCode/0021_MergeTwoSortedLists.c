/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* currA; 
    struct ListNode* currB; 
    struct ListNode* currC; 
    struct ListNode* headC;
    currA = list1;
    currB = list2;
    if (currA != NULL && currB != NULL) {
        if (currA->val < currB->val) {
            currC = currA;
            currA = currA->next;
            headC = currC;
        } else if (currA->val > currB->val) {
            currC = currB;
            currB = currB->next;
            headC = currC;
        } else if (currA->val == currB->val) {
            currC = currA;
            currA = currA->next;
            headC = currC;
            currC->next = currB;
            currB = currB->next;
            currC = currC->next;
        }
        while (currA->next != NULL && currB->next != NULL) {
            if (currA->val < currB->val) {
                currC->next = currA;
                currA = currA->next;
                currC = currC->next;
            } else if (currA->val > currB->val) {
                currC->next = currB;
                currB = currB->next;
                currC = currC->next;
            } else if (currA->val == currB->val) {
                currC->next = currA;
                currA = currA->next;
                currC = currC->next;
                currC->next = currB;
                currB = currB->next;
                currC = currC->next;
            }
        }
        if (currA->next != NULL) {
            while (currA->next != NULL) {
                currC->next = currA;
                currA = currA->next;
                currC = currC->next;
            }
        }
        if (currB->next != NULL) {
            while (currB->next != NULL) {
                currC->next = currB;
                currB = currB->next;
                currC = currC->next;
            }
        }
    }

    return headC;
}
