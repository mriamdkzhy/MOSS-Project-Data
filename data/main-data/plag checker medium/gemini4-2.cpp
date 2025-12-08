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

    // Move p2 n+1 nodes ahead
    for (int i = 0; i <= n; i++) {
        p2 = p2->next;
        if (p2 == nullptr) {
            return head; // If n is greater than the length of the list, remove the first node
        }
    }

    // Move p1 and p2 together until p2 reaches the end
    while (p2 != nullptr) {
        p1 = p1->next;
        p2 = p2->next;
    }

    // p1 now points to the node before the nth node from the end
    p1->next = p1->next->next;

    return dummy->next;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;
    head = removeNthFromEnd(head, n);

    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}