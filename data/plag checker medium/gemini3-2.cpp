#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Edge case: empty list or n is greater than the list length
    if (head == nullptr || n > lengthOfList(head)) {
        return head;
    }

    // Two pointers: fast and slow
    ListNode* fast = head;
    ListNode* slow = head;

    // Move fast pointer n positions ahead
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    // Move both pointers together until fast reaches the end
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    // Remove the nth node from the end (slow is pointing to the node before it)
    slow->next = slow->next->next;

    return head;
}

// Helper function to calculate the length of the linked list
int lengthOfList(ListNode* head) {
    int length = 0;
    while (head != nullptr) {
        length++;
        head = head->next;
    }
    return length;
}

int main() {
    // Create a sample linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2; // Remove the 2nd node from the end

    head = removeNthFromEnd(head, n);

    // Print the modified linked list
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;

    return 0;
}