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
        
        // Move first n+1 steps ahead
        for (int i = 0; i <= n; ++i) {
            first = first->next;
        }
        
        // Move first to the end, maintaining the gap
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        
        // Skip the desired node
        ListNode* nodeToDelete = second->next;
        second->next = second->next->next;
        delete nodeToDelete;
        
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

// Helper function to print the list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    head = solution.removeNthFromEnd(head, 2);

    printList(head); // Output: 1 -> 2 -> 3 -> 5 -> nullptr

    // Free the remaining nodes
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}