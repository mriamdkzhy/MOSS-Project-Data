#include <iostream>

struct Node {
  int data;
  Node* next;
};

Node* removeNthFromEnd(Node* head, int n) {
  // Create a dummy node to simplify the process
  Node* dummy = new Node;
  dummy->next = head;

  // Two pointers: fast and slow
  Node* fast = dummy;
  Node* slow = dummy;

  // Move fast pointer n steps ahead
  for (int i = 0; i < n; i++) {
    fast = fast->next;
  }

  // Move both pointers simultaneously until fast reaches the end
  while (fast->next != nullptr) {
    fast = fast->next;
    slow = slow->next;
  }

  // Remove the nth node from the end
  slow->next = slow->next->next;

  // Return the head of the modified linked list
  return dummy->next;
}

// Function to create a new node
Node* newNode(int data) {
  Node* node = new Node;
  node->data = data;
  node->next = nullptr;
  return node;
}

// Function to print the linked list
void printList(Node* head) {
  while (head != nullptr) {
    std::cout << head->data << " ";
    head = head->next;
  }
  std::cout << std::endl;
}

int main() {
  // Create the linked list
  Node* head = newNode(1);
  head->next = newNode(2);
  head->next->next = newNode(3);
  head->next->next->next = newNode(4);
  head->next->next->next->next = newNode(5);

  // Remove the 2nd node from the end (4)
  head = removeNthFromEnd(head, 2);

  // Print the modified linked list
  printList(head);

  return 0;
}