#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Edge case: empty list or n is greater than the length of the list
    if (head == NULL || n > length(head)) {
        return head;
    }

    // Two pointers: slow and fast
    ListNode* slow = head;
    ListNode* fast = head;

    // Move fast pointer n nodes ahead
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    // If fast reaches the end, it means we need to remove the first node
    if (fast == NULL) {
        return head->next;
    }

    // Move both pointers together until fast reaches the end
    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    // Remove the node pointed to by slow
    slow->next = slow->next->next;

    return head;
}

int length(ListNode* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;
    head = removeNthFromEnd(head, n);

    // Print the modified linked list
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}