#include <iostream>
using namespace std;

template<class Type>
struct nodeType {
  Type info;
  nodeType<Type> *link;
};

template<class Type>
class linkedListType {
public:
  const linkedListType<Type>& operator=(const linkedListType<Type>&);  
  void initializeList();
  bool isEmpty() const;
  void print() const;
  int length() const;
  void destroyList();
  Type front() const;
  Type back() const;
  virtual bool search(const Type& searchItem) const = 0;
  virtual bool insertFirst(const Type& newItem) const = 0;
  virtual bool insertLast(const Type& newItem) const = 0;
  virtual void deleteNode(const Type& deleteItem) = 0;

protected:
  int count;
  nodeType<Type> *first;
  nodeType<Type> *last;
private:
  void copyList(const linkedListType<Type>& otherList);
};

template<class Type>
bool linkedListType<Type>::isEmpty() const { return first == nullptr; }

template<class Type>
void linkedListType<Type>::print() const {
  nodeType<Type>* it = first;
  cout << "Your list: \n";
  while (it->link != nullptr) {
    cout << it->info << "->";
    it = it->link;
  }
  cout << it->info << '\n';
}

template<clas Type>
int linkedListType::length() const { return count; }

template<class Type>
class linkedListIterator {
public:
  linkedListIterator(); 
  linkedListIterator(nodeType<Type> *ptr);

  linkedListIterator<Type> operator++();

  Type operator*();
  bool operator==(const linkedListIterator<Type>& right) const;
  bool operator!=(const linkedListIterator<Type>& right) const;

private:
  nodeType<Type> *current;
};

template<class Type>
linkedListIterator<Type>::linkedListIterator() { current = nullptr; }

template<class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type> *ptr) { current = ptr; }

template<class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++() {
  current = current->link;
  return *this;
}

template<class Type>
Type linkedListIterator<Type>::operator*() { return current->info; }

template<class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right) const {
  return (current == right.current);
}

template<class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right) const {
  return !(current == right.current);
}

template<class Type>
nodeType<Type>* backwardBuildList() {
  nodeType<Type> *first = nullptr, *newNode = nullptr;
  int num;

  cout << "Enter a list of integers ending with -999.\n";
  cin >> num;
  
  while (num != -999) {
    newNode = new nodeType<Type>;
    newNode->info = num;
    // this is being stored before first element
    newNode->link = first;
    
    // set first pointer to the new node
    first = newNode;

    cin >> num;
  }

  return first;
}

template<class Type>
nodeType<Type>* forwardBuildList() {
  nodeType<Type> *first = nullptr, *last, *newNode;
  int num;

  cout << "Enter a list of integers ending with -999.\n";
  cin >> num;

  first = nullptr;

  while (num != -999) {
    newNode = new nodeType<Type>;
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

template<class Type>
void printList(nodeType<Type>* list) {
  cout << "Your list: \n";
  while (list->link != nullptr) {
    cout << list->info << "->";
    list = list->link;
  }
  cout << list->info << '\n';
}

int main() {
  nodeType<int> *head = backwardBuildList<int>();
  nodeType<int> *curr = head;
  printList(curr);
}
