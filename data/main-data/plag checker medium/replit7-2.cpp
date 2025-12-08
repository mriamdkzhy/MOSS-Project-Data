#include <iostream>

struct Node {
  int data;
  Node* next;
};

Node* removeNthFromEnd(Node* head, int n) {
  // If the list is empty or n is 0, return the head
  if (head == nullptr || n == 0) {
    return head;
  }

  // Create two pointers, fast and slow, both starting at the head
  Node* fast = head;
  Node* slow = head;

  // Move the fast pointer n steps ahead
  for (int i = 0; i < n; i++) {
    if (fast == nullptr) {
      return head; // n is greater than the length of the list
    }
    fast = fast->next;
  }

  // If fast is nullptr, it means n is greater than the length of the list
  if (fast == nullptr) {
    return head;
  }

  // Now, fast is n steps ahead of slow. Move both pointers together until fast reaches the end of the list
  while (fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next;
  }

  // Now, slow points to the node before the nth node from the end.
  // Remove the nth node by connecting slow's next to the next node after slow
  slow->next = slow->next->next;

  return head;
}

int main() {
  // Example usage
  Node* head = new Node{1, new Node{2, new Node{3, new Node{4, new Node{5, nullptr}}}}};
  int n = 2; // Remove the 2nd node from the end

  head = removeNthFromEnd(head, n);

  // Print the modified linked list
  Node* current = head;
  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << std::endl;

  return 0;
}