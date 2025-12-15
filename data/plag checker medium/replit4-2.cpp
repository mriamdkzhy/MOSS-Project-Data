#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == NULL || n == 0) {
        return head;
    }

    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* fast = dummy;
    ListNode* slow = dummy;

    // Move 'fast' pointer n steps ahead
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    // Now 'fast' and 'slow' are n steps apart
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // 'slow' now points to the node before the node to be removed
    slow->next = slow->next->next;

    return dummy->next;
}

int main() {
    // Example usage:
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;
    ListNode* newHead = removeNthFromEnd(head, n);

    // Print the updated linked list
    while (newHead != NULL) {
        std::cout << newHead->val << " ";
        newHead = newHead->next;
    }
    std::cout << std::endl;

    return 0;
}