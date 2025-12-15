#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* first = dummy;
    ListNode* second = dummy;

    // Move second pointer n nodes ahead
    for (int i = 0; i < n + 1; i++) {
        second = second->next;
    }

    // Move both pointers together until second reaches the end
    while (second != NULL) {
        first = first->next;
        second = second->next;
    }

    // Remove the node pointed to by first->next
    first->next = first->next->next;

    return dummy->next;
}

int main() {
    // Create a linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2; // Remove the 2nd node from the end

    ListNode* newHead = removeNthFromEnd(head, n);

    // Print the modified linked list
    while (newHead != NULL) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }

    return 0;
}