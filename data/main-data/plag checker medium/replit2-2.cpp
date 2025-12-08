#include <iostream>

struct Node {
  int data;
  Node* next;
};

Node* removeNthFromEnd(Node* head, int n) {
  // Handle the case when the list is empty
  if (head == nullptr) {
    return nullptr;
  }

  // Create a dummy node to make the code cleaner and handle the case when n is equal to the length of the list
  Node* dummy = new Node;
  dummy->next = head;

  // Use two pointers, fast and slow, initialized at the dummy node
  Node* fast = dummy;
  Node* slow = dummy;

  // Move fast pointer n steps ahead
  for (int i = 0; i < n; i++) {
    fast = fast->next;
    if (fast == nullptr) {
      return head; // If n is greater than the length of the list, return the original head
    }
  }

  // Move fast and slow pointers together until fast reaches the end
  while (fast->next != nullptr) {
    fast = fast->next;
    slow = slow->next;
  }

  // Now, slow points to the node before the node to be removed
  slow->next = slow->next->next;

  // Return the head of the modified list
  return dummy->next;
}

int main() {
  // Create a sample linked list
  Node* head = new Node{1, new Node{2, new Node{3, new Node{4, new Node{5, nullptr}}}}};

  // Remove the 2nd node from the end
  head = removeNthFromEnd(head, 2);

  // Print the modified linked list
  Node* current = head;
  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << std::endl;

  return 0;
}