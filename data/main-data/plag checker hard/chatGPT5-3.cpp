#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to handle edge cases (like removing the head)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Initialize two pointers starting from the dummy node
        ListNode* first = dummy;
        ListNode* second = dummy;
        
        // Move the first pointer n+1 steps ahead to create a gap of n between first and second
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }
        
        // Move both pointers until the first pointer reaches the end
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        
        // The second pointer is now just before the node to be deleted
        ListNode* nodeToDelete = second->next;
        second->next = second->next->next;  // Remove the nth node
        
        // Free the memory of the node to be deleted
        delete nodeToDelete;
        
        // Return the new head (dummy->next)
        ListNode* newHead = dummy->next;
        delete dummy;  // Free the dummy node
        return newHead;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Main function to test the solution
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    ListNode* head = createList(arr, 5);
    
    std::cout << "Original list: ";
    printList(head);
    
    Solution sol;
    head = sol.removeNthFromEnd(head, 2);  // Remove the 2nd node from the end
    
    std::cout << "Updated list after removing 2nd node from end: ";
    printList(head);
    
    return 0;
}
