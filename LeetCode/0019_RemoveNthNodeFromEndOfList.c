/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* curr = head;
    struct ListNode* delay = head;
    int count = 0;

    if (head->next == NULL) {
        return NULL;
    }

    while (count != n && curr != NULL) {
        curr = curr->next;
        count++;
    }
    if (curr == NULL) {
        head = head->next;
        return head;
    }

    curr = curr->next;
    while (curr != NULL) {
        curr = curr->next;
        delay = delay->next;
    }
    if (delay != NULL) {
        if (delay->next != NULL) {
            delay->next = delay->next->next;
        }
    }
    return head;
}
