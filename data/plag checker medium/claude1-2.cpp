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
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;
        
        // Advance first pointer so that the gap between first and second is n nodes apart
        for (int i = 1; i <= n + 1; i++) {
            first = first->next;
        }
        
        // Move first to the end, maintaining the gap
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        
        // Second is now at the (n+1)th node from the end
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
    
    // Test case 2: Remove 1st node from the end (last node)
    int arr2[] = {1, 2, 3};
    ListNode* head2 = createList(arr2, 3);
    std::cout << "\nOriginal list: ";
    printList(head2);
    head2 = solution.removeNthFromEnd(head2, 1);
    std::cout << "After removing 1st node from the end: ";
    printList(head2);
    
    // Test case 3: Remove the only node
    int arr3[] = {1};
    ListNode* head3 = createList(arr3, 1);
    std::cout << "\nOriginal list: ";
    printList(head3);
    head3 = solution.removeNthFromEnd(head3, 1);
    std::cout << "After removing the only node: ";
    printList(head3);
    
    return 0;
}