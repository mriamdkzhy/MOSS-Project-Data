#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* first = dummy;
    ListNode* second = dummy;

    // Move first n+1 steps ahead
    for (int i = 0; i <= n; ++i) {
        first = first->next;
    }

    // Move first to the end, maintaining the gap
    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }

    // Skip the desired node
    ListNode* nodeToDelete = second->next;
    second->next = second->next->next;
    delete nodeToDelete;

    ListNode* newHead = dummy->next;
    delete dummy;
    return newHead;
}

// Helper function to print the list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Helper function to create a new list node
ListNode* createNode(int val) {
    return new ListNode(val);
}

int main() {
    // Example usage
    ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    std::cout << "Original list: ";
    printList(head);

    int n = 2;
    head = removeNthFromEnd(head, n);

    std::cout << "List after removing " << n << "th node from end: ";
    printList(head);

    return 0;
}