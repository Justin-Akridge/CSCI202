#include <iostream>
using namespace std;

struct nodeType {
  int info;
  nodeType* link;
};

nodeType* backwardBuildList() {
  nodeType *first = nullptr, *newNode = nullptr;
  int num;

  cout << "Enter a list of integers ending with -999.\n";
  cin >> num;
  
  while (num != -999) {
    newNode = new nodeType;
    newNode->info = num;
    // this is being stored before first element
    newNode->link = first;
    
    // set first pointer to the new node
    first = newNode;

    cin >> num;
  }

  return first;
}

nodeType* forwardBuildList() {
  nodeType *first = nullptr, *last, *newNode;
  int num;

  cout << "Enter a list of integers ending with -999.\n";
  cin >> num;

  first = nullptr;

  while (num != -999) {
    newNode = new nodeType;
    newNode->info = num;
    newNode->link = nullptr;

    if (first == nullptr) {
      first = newNode;
      last = newNode;
    } else {
      last->link = newNode;
      last = newNode;
      last->link = nullptr;
    }
    cin >> num;
  }
  return first;
}

void printList(nodeType* list) {
  cout << "Your list: \n";
  while (list != nullptr) {
    cout << "->" << list->info;
    list = list->link;
  }
}

int main() {
  nodeType *head = backwardBuildList();
  nodeType *curr = head;
  printList(curr);
}







