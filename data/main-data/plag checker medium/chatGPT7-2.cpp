#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Create a dummy node, which simplifies edge cases such as removing the head
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    
    ListNode* first = dummy;
    ListNode* second = dummy;
    
    // Move first n+1 steps ahead so that the second pointer will point to the node before the one to remove
    for (int i = 0; i <= n; i++) {
        first = first->next;
    }
    
    // Move both first and second until first reaches the end
    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }
    
    // Remove the nth node from the end
    ListNode* nodeToRemove = second->next;
    second->next = nodeToRemove->next;
    
    // Free the memory of the node to remove
    delete nodeToRemove;
    
    // Return the new head (could be different if the head was removed)
    ListNode* newHead = dummy->next;
    delete dummy;  // Clean up the dummy node
    return newHead;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    // Creating a sample linked list 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    int n = 2; // Remove the 2nd node from the end
    
    std::cout << "Original list: ";
    printList(head);
    
    // Removing the nth node from the end
    head = removeNthFromEnd(head, n);
    
    std::cout << "List after removing " << n << "th node from end: ";
    printList(head);
    
    return 0;
}
