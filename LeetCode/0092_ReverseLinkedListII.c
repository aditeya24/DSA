/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode* firstNode = head;
    int i;
    for (i = 0; i < left-1; i++) {
        firstNode = firstNode->next;
    }
    struct ListNode* start = head;
    for (i = 0; i < left-2; i++) {
        start = start->next;
    }
    struct ListNode* temp;
    if (firstNode != NULL) {
        if (firstNode->next != NULL) {
            temp = firstNode->next;
        }
    
        while (firstNode->next != NULL && i < right-2) {
            firstNode->next = temp->next;
            temp->next = start->next;
            start->next = temp;
            temp = firstNode->next;
            i++;
        }
    }

    return head; 
}
