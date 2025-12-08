#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* p1 = dummy;
    ListNode* p2 = dummy;

    // Move p2 n+1 nodes forward
    for (int i = 0; i <= n; i++) {
        p2 = p2->next;
    }

    // Move both pointers together until p2 reaches the end
    while (p2 != NULL) {
        p1 = p1->next;
        p2 = p2->next;
    }

    // Remove the node pointed to by p1->next
    p1->next = p1->next->next;

    return dummy->next;
}

int main() {
    // Create a sample linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2; // Remove the 2nd node from the end

    ListNode* newHead = removeNthFromEnd(head, n);

    // Print the modified linked list
    while (newHead != NULL) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;

    return 0;
}