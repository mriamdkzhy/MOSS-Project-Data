#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Create a dummy node to simplify edge cases (e.g. removing the head)
    ListNode* dummy = new ListNode(0, head);
    ListNode* first = dummy;
    ListNode* second = dummy;
    
    // Move `first` n + 1 steps forward, so there is a gap of n between `first` and `second`
    for (int i = 0; i <= n; ++i) {
        first = first->next;
    }
    
    // Move both pointers until `first` reaches the end of the list
    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }
    
    // Skip the nth node from the end
    ListNode* nodeToDelete = second->next;
    second->next = second->next->next;
    
    // Free memory for the removed node
    delete nodeToDelete;
    
    // Return the new head of the list
    ListNode* newHead = dummy->next;
    delete dummy;  // Free the dummy node
    return newHead;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "null" << endl;
}

int main() {
    // Example: 1 -> 2 -> 3 -> 4 -> 5, n = 2
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    int n = 2;
    head = removeNthFromEnd(head, n);

    cout << "Updated list after removing " << n << "th node from the end: ";
    printList(head);

    return 0;
}
