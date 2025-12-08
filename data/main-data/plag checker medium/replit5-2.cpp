#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Create a dummy node for easier manipulation
    ListNode* dummy = new ListNode(0, head);

    // Two pointers: 'fast' moves ahead by n+1, 'slow' stays n nodes behind
    ListNode* fast = dummy;
    ListNode* slow = dummy;

    // Move 'fast' n+1 steps ahead
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // Now, 'fast' and 'slow' are n nodes apart
    // Move 'slow' and 'fast' together until 'fast' reaches the end of the list
    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    // 'slow' is now pointing to the node before the one to be removed
    slow->next = slow->next->next;

    // Return the head of the modified list
    return dummy->next;
}

int main() {
    // Example Usage:
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2; // Remove the 2nd node from the end

    head = removeNthFromEnd(head, n);

    // Print the modified linked list
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}