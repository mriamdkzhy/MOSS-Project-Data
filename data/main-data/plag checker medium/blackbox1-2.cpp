// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* main = head;
    ListNode* ref = head;

    // Move ref n steps ahead
    for (int i = 0; i < n; i++) {
        ref = ref->next;
    }

    // If ref reaches the end, remove the head node
    if (ref == NULL) {
        return head->next;
    }

    // Move both pointers until ref reaches the end
    while (ref->next != NULL) {
        main = main->next;
        ref = ref->next;
    }

    // Remove the nth node from the end
    main->next = main->next->next;

    return head;
}