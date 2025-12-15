#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    // If the list is empty or n is zero, return the head
    if (head == nullptr || n == 0) {
        return head;
    }
    
    // Create two pointers, 'fast' and 'slow', both pointing to the head
    ListNode* fast = head;
    ListNode* slow = head;

    // Move 'fast' pointer 'n' positions ahead of 'slow'
    for (int i = 0; i < n; ++i) {
        if (fast == nullptr) {
            return head; // If 'fast' reaches the end before 'n', return the head
        }
        fast = fast->next;
    }

    // If 'fast' is now at the end, 'slow' is at the (n-1)th node from the end
    if (fast == nullptr) {
        return head->next; // If 'fast' is at the end, it means we need to remove the first node
    }

    // Move both 'fast' and 'slow' pointers together until 'fast' reaches the end
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    // Now 'slow' points to the node before the one we need to remove
    slow->next = slow->next->next;

    return head;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;

    ListNode* newHead = removeNthFromEnd(head, n);

    while (newHead != nullptr) {
        std::cout << newHead->val << " ";
        newHead = newHead->next;
    }
    std::cout << std::endl;

    return 0;
}