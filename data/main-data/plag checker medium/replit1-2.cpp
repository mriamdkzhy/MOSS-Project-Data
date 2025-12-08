#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

Node* removeNthFromEnd(Node* head, int n) {
  // Step 1: Create a dummy node to simplify handling the edge case of removing the first node
  Node* dummy = new Node();
  dummy->next = head;

  // Step 2: Initialize two pointers, fast and slow
  Node* fast = dummy;
  Node* slow = dummy;

  // Step 3: Move the fast pointer n steps ahead
  for (int i = 0; i < n; i++) {
    fast = fast->next;
  }

  // Step 4: Move both pointers simultaneously until fast reaches the end of the list
  while (fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next;
  }

  // Step 5: Remove the nth node from the end by connecting its previous node to its next node
  slow->next = slow->next->next;

  // Step 6: Return the head of the modified list
  return dummy->next;
}

// Function to create a new node
Node* newNode(int data) {
  Node* node = new Node();
  node->data = data;
  node->next = nullptr;
  return node;
}

// Function to print the linked list
void printList(Node* head) {
  while (head != nullptr) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

int main() {
  // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
  Node* head = newNode(1);
  head->next = newNode(2);
  head->next->next = newNode(3);
  head->next->next->next = newNode(4);
  head->next->next->next->next = newNode(5);

  // Remove the 2nd node from the end (which is 4)
  head = removeNthFromEnd(head, 2);

  // Print the modified linked list: 1 -> 2 -> 3 -> 5
  printList(head);

  return 0;
}