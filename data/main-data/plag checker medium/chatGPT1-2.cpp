#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node which points to the head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Move the fast pointer n steps ahead
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }
        
        // Move both fast and slow pointers until fast reaches the end
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Skip the nth node
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        
        // Free the memory of the node to delete
        delete nodeToDelete;
        
        // Return the head, which is dummy->next
        ListNode* newHead = dummy->next;
        delete dummy;  // Free the memory of the dummy node
        return newHead;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to add a node to the linked list
ListNode* addNode(ListNode* head, int val) {
    if (head == NULL) {
        return new ListNode(val);
    }
    ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new ListNode(val);
    return head;
}

int main() {
    // Example Usage:
    Solution solution;

    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head = addNode(head, 2);
    head = addNode(head, 3);
    head = addNode(head, 4);
    head = addNode(head, 5);
    
    cout << "Original list: ";
    printList(head);
    
    // Remove the 2nd node from the end (resulting list should be: 1 -> 2 -> 3 -> 5)
    head = solution.removeNthFromEnd(head, 2);
    
    cout << "List after removal: ";
    printList(head);
    
    return 0;
}
