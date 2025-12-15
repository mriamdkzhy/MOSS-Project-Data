#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* first = dummy;
    ListNode* second = dummy;

    // Move first pointer n + 1 steps ahead
    for (int i = 0; i <= n; i++) {
        first = first->next;
        if (first == nullptr) {
            return head; // If n is greater than the length of the list, remove the first node
        }
    }

    // Move both pointers together until first reaches the end
    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }

    // Remove the node pointed to by second->next
    second->next = second->next->next;

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
    while (newHead != nullptr) {
        std::cout << newHead->val << " ";
        newHead = newHead->next;
    }
    std::cout << std::endl;

    return 0;
}