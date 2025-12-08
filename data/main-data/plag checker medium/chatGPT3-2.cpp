#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Create a dummy node that will make edge cases easier to handle
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    
    ListNode* first = dummy;
    ListNode* second = dummy;

    // Move the first pointer so that it has a gap of n+1 between it and the second pointer
    for (int i = 0; i <= n; ++i) {
        first = first->next;
    }

    // Move both pointers until the first pointer reaches the end of the list
    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }

    // Now, second is pointing at the node before the one that needs to be removed
    ListNode* nodeToDelete = second->next;
    second->next = second->next->next;

    // Free memory of the node being removed
    delete nodeToDelete;

    // Get the real head from the dummy node and delete the dummy node
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

int main() {
    // Example usage:
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original list: ";
    printList(head);

    int n = 2; // Remove the 2nd node from the end
    head = removeNthFromEnd(head, n);

    std::cout << "Updated list: ";
    printList(head);

    return 0;
}
