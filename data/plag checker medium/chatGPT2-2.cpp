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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to handle edge cases like removing the first node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Two pointers: slow and fast
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        // Move the fast pointer n+1 steps ahead so there's a gap of n between slow and fast
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }
        
        // Move both slow and fast pointers until fast reaches the end of the list
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Remove the nth node from the end
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        
        // Free the memory of the node to delete
        delete toDelete;
        
        // Return the new head (might be the original head or a new one if the first node was deleted)
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Create a list [1, 2, 3, 4, 5]
    int arr[] = {1, 2, 3, 4, 5};
    ListNode* head = createList(arr, 5);
    
    cout << "Original list: ";
    printList(head);
    
    Solution solution;
    // Remove the 2nd node from the end
    head = solution.removeNthFromEnd(head, 2);
    
    cout << "List after removing 2nd node from end: ";
    printList(head);
    
    return 0;
}
