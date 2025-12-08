#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Create two pointers
    ListNode* fast = head;
    ListNode* slow = head;

    // Move fast pointer n steps ahead
    for (int i = 0; i < n; ++i) {
        fast = fast->next;
    }

    // If fast is nullptr, it means we need to remove the first node
    if (!fast) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // Move both fast and slow pointers until fast reaches the end
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    // Now slow is at the previous node of the node to be deleted
    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;

    return head;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original List: ";
    printList(head);

    int n = 2;
    head = removeNthFromEnd(head, n);

    std::cout << "List after removing " << n << "th node from the end: ";
    printList(head);

    return 0;
}
