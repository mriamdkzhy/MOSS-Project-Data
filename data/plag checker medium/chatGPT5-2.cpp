#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to handle edge cases like removing the head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Initialize two pointers, both starting at the dummy node
        ListNode* first = dummy;
        ListNode* second = dummy;
        
        // Move the first pointer n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }
        
        // Move both pointers together until the first pointer reaches the end
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        
        // Now the second pointer is right before the node to be removed
        ListNode* nodeToDelete = second->next;
        second->next = nodeToDelete->next;
        
        // Free memory for the deleted node
        delete nodeToDelete;
        
        // The dummy node's next points to the modified head
        ListNode* newHead = dummy->next;
        delete dummy;
        
        return newHead;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    Solution sol;
    
    // Remove the 2nd node from the end (expected list: 1 -> 2 -> 3 -> 5)
    head = sol.removeNthFromEnd(head, 2);
    
    // Print the modified list
    printList(head);
    
    return 0;
}
