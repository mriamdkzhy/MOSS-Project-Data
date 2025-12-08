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

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Helper function to create a linked list from an array
ListNode* createList(const std::vector<int>& vals) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int val : vals) {
        current->next = new ListNode(val);
        current = current->next;
    }
    ListNode* head = dummy->next;
    delete dummy;
    return head;
}

int main() {
    std::vector<int> vals = {1, 2, 3, 4, 5};
    ListNode* head = createList(vals);
    int n = 2;

    std::cout << "Original list: ";
    printList(head);

    head = removeNthFromEnd(head, n);

    std::cout << "List after removing " << n << "th node from end: ";
    printList(head);

    return 0;
}