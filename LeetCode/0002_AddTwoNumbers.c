/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* l3 = NULL;
    struct ListNode* curr = NULL;
    struct ListNode* temp = NULL;
    int sum = 0, carry = 0;
    while (l1 != NULL && l2 != NULL) {
        sum = l1->val + l2->val + carry;
        carry = sum / 10;
        l1 = l1->next;
        l2 = l2->next;
        temp = createNode(sum > 9 ? sum % 10 : sum );
        if (l3 == NULL) {
            l3 = temp;
            curr = temp;
        } else {
            curr->next = temp;
            curr = curr->next;
        }
    }
    while (l1 != NULL) {
        sum = l1->val + carry;
        carry = sum / 10;
        l1 = l1->next;
        temp = createNode(sum > 9 ? sum % 10 : sum );
        if (l3 == NULL) {
            l3 = temp;
            curr = temp;
        } else {
            curr->next = temp;
            curr = curr->next;
        }
    }
    while (l2 != NULL) {
         sum = l2->val + carry;
        carry = sum / 10;
        l2 = l2->next;
        temp = createNode(sum > 9 ? sum % 10 : sum );
        if (l3 == NULL) {
            l3 = temp;
            curr = temp;
        } else {
            curr->next = temp;
            curr = curr->next;
        }       
    }
    if (carry != 0) {
        temp = createNode(carry);
        curr->next = temp;
    }
    return l3; 
}
