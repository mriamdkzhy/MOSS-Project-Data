#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Create a dummy node to simplify the logic.
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    // Initialize two pointers:
    // - fast: moves n steps ahead.
    // - slow: remains at the dummy node.
    ListNode* fast = dummy;
    ListNode* slow = dummy;

    // Move fast pointer n steps ahead.
    for (int i = 0; i < n; ++i) {
        fast = fast->next;
    }

    // Move fast and slow pointers together until fast reaches the end.
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    // Now, slow points to the node before the node we want to remove.
    slow->next = slow->next->next;

    // Return the head of the modified list.
    return dummy->next;
}

int main() {
    // Example linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2; // Remove the 2nd node from the end (i.e., 4)

    ListNode* newHead = removeNthFromEnd(head, n);

    // Print the updated linked list: 1 -> 2 -> 3 -> 5
    while (newHead != nullptr) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;

    return 0;
}