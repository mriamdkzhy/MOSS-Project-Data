#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    // If the list is empty or n is 0, return the head
    if (head == nullptr || n == 0) {
        return head;
    }
    // Create two pointers, fast and slow, both pointing to the head
    ListNode* fast = head;
    ListNode* slow = head;
    // Move the fast pointer n nodes ahead
    for (int i = 0; i < n; i++) {
        if (fast == nullptr) {
            return head; // If n is greater than the length of the list, return the head
        }
        fast = fast->next;
    }
    // If the fast pointer is nullptr, it means n is greater than the length of the list
    // and we need to remove the first node
    if (fast == nullptr) {
        return head->next;
    }
    // Move both pointers until the fast pointer reaches the end of the list
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    // Remove the node pointed to by slow
    slow->next = slow->next->next;
    return head;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Remove the 2nd node from the end (which is node 4)
    head = removeNthFromEnd(head, 2);

    // Print the updated linked list: 1 -> 2 -> 3 -> 5
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    return 0;
}