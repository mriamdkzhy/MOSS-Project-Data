#include <iostream>

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to simplify edge cases (like removing the head).
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* first = dummy;
        ListNode* second = dummy;
        
        // Move first pointer n+1 steps ahead so that there's a gap of n nodes between first and second
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }
        
        // Move both first and second until first reaches the end
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        
        // Now second is at the node just before the node to be removed.
        ListNode* nodeToRemove = second->next;
        second->next = second->next->next;
        
        // Free memory for the node being removed
        delete nodeToRemove;
        
        // Return the head of the modified list
        ListNode* newHead = dummy->next;
        delete dummy; // Delete dummy node to avoid memory leak
        return newHead;
    }
};

// Helper function to print the list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    Solution solution;
    int n = 2;
    head = solution.removeNthFromEnd(head, n);
    
    // Print the updated list
    printList(head);
    
    // Free the memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}
