#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Create two pointers, one pointing to the beginning of the list
    // and the other pointing n nodes ahead.
    ListNode* fast = head;
    ListNode* slow = head;

    // Move the fast pointer n nodes ahead
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    // If n is greater than the length of the list, return NULL
    if (fast == NULL) {
        return head->next;
    }

    // Move both pointers until the fast pointer reaches the end
    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    // The slow pointer is now pointing to the node before the nth node from the end
    slow->next = slow->next->next;

    return head;
}

int main() {
    // Create a linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;

    // Remove the nth node from the end
    ListNode* newHead = removeNthFromEnd(head, n);

    // Print the modified linked list
    while (newHead != NULL) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }

    return 0;
}