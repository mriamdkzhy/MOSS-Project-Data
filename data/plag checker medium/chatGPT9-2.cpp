#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node that points to the head
        ListNode* dummy = new ListNode(0, head);
        
        // Initialize two pointers starting at the dummy node
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Move the fast pointer n steps ahead
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }
        
        // Move both fast and slow pointers until fast reaches the end of the list
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Now slow points to the node before the one we want to remove
        ListNode* nodeToRemove = slow->next;
        slow->next = slow->next->next;
        
        // Clean up the memory
        delete nodeToRemove;
        
        // Return the head of the new list
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example: creating a list 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    int n = 2; // Remove the 2nd node from the end

    // Remove nth node 
