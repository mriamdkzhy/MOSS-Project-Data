#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Step 1: Create two pointers, fast and slow.
    ListNode *fast = head;
    ListNode *slow = head;

    // Step 2: Move the fast pointer n nodes ahead.
    for (int i = 0; i < n; ++i) {
        if (fast == nullptr) {
            return head; // n is greater than the length of the list
        }
        fast = fast->next;
    }

    // Step 3: Move both pointers simultaneously until the fast pointer reaches the end of the list.
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    // Step 4: Remove the node pointed to by slow.
    ListNode* temp = slow->next;
    slow->next = temp->next;
    delete temp;

    return head;
}

int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;

    ListNode* newHead = removeNthFromEnd(head, n);

    // Print the modified linked list
    while (newHead != nullptr) {
        std::cout << newHead->val << " ";
        newHead = newHead->next;
    }
    std::cout << std::endl;

    return 0;
}