#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node that points to the head.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Two pointers: slow and fast
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Move fast pointer n+1 steps ahead (to create a gap of n nodes)
        for (int i = 1; i <= n + 1; i++) {
            fast = fast->next;
        }

        // Move both fast and slow until fast reaches the end
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Slow is now before the node that needs to be removed
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        
        // Free memory of the node to be deleted
        delete nodeToDelete;

        // Return the modified list
        ListNode* newHead = dummy->next;
        delete dummy; // Delete the dummy node to prevent memory leak
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

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    int n = 2;
    
    cout << "Original List: ";
    printList(head);

    head = solution.removeNthFromEnd(head, n);

    cout << "Modified List after removing " << n << "th node from the end: ";
    printList(head);

    return 0;
}
