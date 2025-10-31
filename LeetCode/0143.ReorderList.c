/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void reorderList(struct ListNode* head) {
    struct ListNode* fast = head; 
    struct ListNode* slow = head; 
    struct ListNode* stack;
    struct ListNode* firstNode;
    struct ListNode* temp;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    temp = slow;
    slow = slow->next;
    temp->next = NULL;

    stack = firstNode = slow;
    if (firstNode != NULL) {
        if (firstNode->next != NULL) {
            temp = firstNode->next;
        }
        while (firstNode->next != NULL) {
            firstNode->next = temp->next;
            temp->next = stack;
            stack = temp;
            temp = firstNode->next;
        }
    }


    fast = head;
    while (stack != NULL) {
        temp = stack;
        stack = stack->next;
        temp->next = fast->next;
        fast->next = temp;
        fast = temp->next;
    }
}
