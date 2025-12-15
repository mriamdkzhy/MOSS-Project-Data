#include <iostream>

// Definition for singly-linked list
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
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;
        
        // Advance first pointer by n+1 steps
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }
        
        // Move first to the end, maintaining the gap
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        
        // Remove the nth node from the end
        ListNode* temp = second->next;
        second->next = second->next->next;
        delete temp;
        
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    Solution solution;
    
    // Test case 1: Remove 2nd node from the end
    int arr1[] = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(arr1, 5);
    std::cout << "Original list: ";
    printList(head1);
    head1 = solution.removeNthFromEnd(head1, 2);
    std::cout << "After removing 2nd node from the end: ";
    printList(head1);
    
    // Test case 2: Remove the only node
    int arr2[] = {1};
    ListNode* head2 = createList(arr2, 1);
    std::cout << "\nOriginal list: ";
    printList(head2);
    head2 = solution.removeNthFromEnd(head2, 1);
    std::cout << "After removing the only node: ";
    printList(head2);
    
    return 0;
}