#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node *prev;
  Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Додавання елемента в кінець списку
void addBack(Node *&head, int value) {
  Node *newNode = new Node(value);
  if (!head) {
    head = newNode;
  } else {
    Node *tail = head;
    while (tail->next) {
      tail = tail->next;
    }
    tail->next = newNode;
    newNode->prev = tail;
  }
}

// Виведення списку
void printList(Node *head) {
  Node *temp = head;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

// Підрахунок непарних елементів (ітераційно)
int countOddElementsIterative(Node *head) {
  int count = 0;
  Node *temp = head;
  while (temp) {
    if (temp->data % 2 != 0)
      count++;
    temp = temp->next;
  }
  return count;
}

// Видалення списку
void deleteList(Node *&head) {
  while (head) {
    Node *temp = head;
    head = head->next;
    delete temp;
  }
}

int main() {
  Node *head = nullptr;
  addBack(head, 4);
  addBack(head, -7);
  addBack(head, 8);
  addBack(head, 13);

  cout << "Список: ";
  printList(head);

  int count = countOddElementsIterative(head);
  cout << "Кількість непарних елементів: " << count << endl;

  deleteList(head);
  return 0;
}
