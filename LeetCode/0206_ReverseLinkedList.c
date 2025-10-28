/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* firstNode = head;
    struct ListNode* temp;
    if (firstNode != NULL) {
        if (firstNode->next != NULL) {
            temp = firstNode->next;
        }
    
        while (firstNode->next != NULL) {
            firstNode->next = temp->next;
            temp->next = head;
            head = temp;
            temp = firstNode->next;
        }
    }

    return head;
}
