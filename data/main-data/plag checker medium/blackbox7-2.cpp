// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* first = head;
    ListNode* second = head;

    // Move first n steps ahead
    for (int i = 0; i < n; i++) {
        first = first->next;
    }

    // If first reaches the end, remove the head node
    if (first == nullptr) {
        return head->next;
    }

    // Move both first and second one step at a time
    while (first->next != nullptr) {
        first = first->next;
        second = second->next;
    }

    // Remove the node pointed to by second
    second->next = second->next->next;

    return head;
}