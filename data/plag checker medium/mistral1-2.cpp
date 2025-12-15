#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to handle the edge case where the head needs to be removed
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Advance the first pointer n+1 steps ahead
        for (int i = 0; i <= n; ++i) {
            first = first->next;
        }

        // Move both pointers until the first pointer reaches the end
        while (first != NULL) {
            first = first->next;
            second = second->next;
        }

        // Remove the nth node from the end
        ListNode* temp = second->next;
        second->next = second->next->next;
        delete temp;

        // Return the new head of the list
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const std::vector<int>& arr) {
    if (arr.empty()) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    Solution solution;
    std::vector<int> arr = {1, 2, 3, 4, 5};
    int n = 2;
    ListNode* head = createLinkedList(arr);
    ListNode* newHead = solution.removeNthFromEnd(head, n);
    printLinkedList(newHead);  // Output should be 1 -> 2 -> 3 -> 5 -> NULL

    // Clean up the memory
    while (newHead != NULL) {
        ListNode* temp = newHead;
        newHead = newHead->next;
        delete temp;
    }

    return 0;
}
