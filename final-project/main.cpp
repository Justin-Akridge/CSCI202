#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>

class Array {
public:
  Array(int _size = 20) {
    arr = new int[_size];
    for (int i = 0; i < _size; i++) {
      arr[i] = 0;
    }
    size_of_array = _size;
    last_index = 0;
  }
  
  ~Array() {
    delete [] arr;
    arr = nullptr;
  }

  void initialize() {
    last_index = 19;
    size_of_array = 10;
    srand(time(NULL));
    for (int i = 0; i <= last_index; i++) {
      arr[i] = rand() % 100;
    }
  }

  void reset() {
    last_index = 0;
  }

  void push() {
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
      int val = rand() % 100;
      print();
      std::cout << " <- " << val << '\n';
      arr[last_index] = val;
      ++last_index;
    }
  }
  
  void pop() {
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
      int val = rand() % 100;
      arr[last_index] = val;
      ++last_index;
    }

    for (int i = last_index-1; i >= 0; i--) {
      print();
      int last_val = arr[last_index - 1];
      std::cout << " -> " << last_val << '\n';
      --last_index;
    }

    std::cout << "[]\n";
    reset(); 
  }

  int size() const {
    return last_index;
  }

  int buffer_size() const {
    return size_of_array;
  }

  void print() {
    std::cout << '[';
    for (int i = 0; i < last_index; i++) {
      std::cout << arr[i];
      if (i < last_index - 1) {
        std::cout << ',';
      }
    }
    std::cout << "]\n";
  }

  void merge(const int left, const int mid, const int right, std::vector<std::vector<int>> &stored_vectors) {
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
    
    // Create temp arrays
    int *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = arr[mid + 1 + j];

    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // copy over array into vectors to push_back hack!
    std::vector<int> left_vector(subArrayOne);
    for (int i = 0; i < subArrayOne; i++)
        left_vector[i] = arr[left + i];

    std::vector<int> right_vector(subArrayTwo);
    for (int j = 0; j < subArrayTwo; j++)
        right_vector[j] = arr[mid + 1 + j];

    stored_vectors.push_back(left_vector);
    stored_vectors.push_back(right_vector);

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            arr[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            arr[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        arr[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
  }

  void merge_sort(const int left, const int right, std::vector<std::vector<int>> &stored_vectors) {
    if (left >= right) {
      return;
    }

    int mid = left + (right - left) / 2;
    merge_sort(left, mid, stored_vectors);
    merge_sort(mid + 1, right, stored_vectors);
    merge(left, mid, right, stored_vectors);
  }

  void initialize_merge_sort() {
    // we only want to call initialize here since we need an array unsorted
    initialize();

    std::vector<std::vector<int>> stored_vectors;

    merge_sort(0, last_index, stored_vectors);


    // need to figure out a way to print this out!
    for (auto it = stored_vectors.rbegin(); it != stored_vectors.rend(); ++it) {
      std::cout << "[";
      for (size_t i = 0; i < it->size(); ++i) {
        std::cout << (*it)[i];
        if (i != it->size() - 1)
          std::cout << ",";
      }
      std::cout << "]\n";
    }

    // Print the final sorted array
    std::cout << "[";
    for (int i = 0; i <= last_index; ++i) {
      std::cout << arr[i];
      if (i != last_index)
        std::cout << ",";
    }
    std::cout << "]" << std::endl;
    reset();
  }

  void selection_sort() {
    // this may need to be initialized
    initialize();
    for (int i = 0; i < last_index; i++) {
      int min = arr[i];
      int swap_index = i;
      for (int j = i; j < last_index; j++) {
        if (arr[j] < min) {
          min = arr[j];
          swap_index = j;
        }
      }

      if (swap_index != i) {
        int temp = arr[i];
        arr[i] = min;
        arr[swap_index] = temp;
      }

      std::cout << "Swapping arr[" << i << "]: " << arr[i]
                << " with arr[" << swap_index << "]: " << arr[i] << "\n\n";
      print();
    }
  }

  void bubble_sort() {
    initialize();
    bool swapped;
    for (int i = 0; i < last_index - 1; i++) {
      swapped = false;
      for (int j = 0; j < last_index - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
          std::swap(arr[j], arr[j+1]);
          swapped = true;
        }
      }

      if (!swapped) {
        break;
      }

      std::cout << '[';
      for (int i = 0; i < last_index; i++) {
        if (i < last_index - 1)
          std::cout << arr[i] << ",";
        else
          std::cout << arr[i] << "]\n";
      }
    }
  }

  int partition(int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high; j++) {
      if (arr[j] < pivot) {
        i++;
        std::swap(arr[i], arr[j]);
      }
    }
    std::cout << '[';
    for (int i = 0; i < last_index; i++) {
      if (i < last_index - 1)
        std::cout << arr[i] << ",";
      else
        std::cout << arr[i] << "]\n";
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
  }

  void quick_sort(int low, int high) {
    if (low < high) {
      int pi = partition(low, high);
      quick_sort(low, pi - 1);
      quick_sort(pi + 1, high);
    }
  }

  void initialize_quick_sort() {
    quick_sort(0, last_index);
  }

  int get_last_index() const {
    return last_index;
  }

private:
  int last_index;
  int size_of_array;
  int *arr;
};

void arrays() {
  Array array;

  std::cout << "An array is a data structure consisting of a collection of elements, of same memory size, each identified by at least one array index or key.\nThere are several different algorithms that can be performed on an array.\n";
  char input;
  do {
    std::cout << "Select the algorithm you would like to see.\n"
              << "1. Push \n"
              << "2. Pop \n"
              << "3. Merge sort \n"
              << "4. Bubble sort \n"
              << "5. Quick sort \n"
              << "6. Selection sort \n"
              << "0. Quit\n"
              << "input: ";
    std::cin >> input;
    switch (input) {
      case '1':
        array.push();
        break;
      case '2':
        array.pop();
        break;
      case '3':
        array.initialize_merge_sort();
        break;
      case '4':
        array.bubble_sort();
        break;
      case '5':
        array.initialize_quick_sort();
        break;
      case '6':
        array.selection_sort();
        break;
      default:
        std::cerr << "Error: Invalid input. Please select number between 1-5\n";
        break;
    }
  }
  while (input != '0');
  // need to reset array to initialization to visualize next operation if requested
  //array.initialize;

}

template <class Type>
struct Node {
  Type value;
  Node *left;
  Node *right;
};

template <class Type>
class binary_tree {
public:
  binary_tree();
  binary_tree(const binary_tree<Type> &other_tree);
  ~binary_tree();

  const binary_tree<Type>& operator=(const binary_tree<Type> &);
  bool is_empty() const;
  void preorder_traversal() const;
  void inorder_traversal() const;
  void postorder_traversal() const;
  int tree_height() const;
  int node_count() const;
  int leaves_count() const;
  void destroy_tree();

  virtual bool search(const Type& search_item) const = 0; 
  virtual void insert(const Type& insert_item) = 0; 
  virtual void delete_node(const Type& delete_item) = 0; 

protected:
    Node<Type>  *root;

private:
    void copy_tree(Node<Type>* &copied_tree_root, 
                  Node<Type>* other_tree_root);
    void destroy(Node<Type>* &p);
    void inorder(Node<Type> *p) const;
    void preorder(Node<Type> *p) const;
    void postorder(Node<Type> *p) const;
    int height(Node<Type> *p) const;
    int max(int x, int y) const;
    int node_count(Node<Type> *p) const;
    int leaves_count(Node<Type> *p) const;
};


template <class Type>
binary_tree<Type>::binary_tree() {
  root = nullptr;
}

template <class Type>
bool binary_tree<Type>::is_empty() const {
  return (root == nullptr);
}


template <class Type>
void binary_tree<Type>::preorder_traversal() const {
  preorder(root);
}

template <class Type>
void binary_tree<Type>::inorder_traversal() const {
  inorder(root);
}

template <class Type>
void binary_tree<Type>::postorder_traversal() const {
  postorder(root);
}

template <class Type>
int binary_tree<Type>::tree_height() const {
  return height(root); 
}

template <class Type>
int binary_tree<Type>::node_count() const {
  node_count(root);
}

template <class Type>
int binary_tree<Type>::leaves_count() const {
  leaves_count(root);
}

template <class Type>
void binary_tree<Type>::destroy_tree() {
  destroy(root);
}

template <class Type>
void binary_tree<Type>::copy_tree(Node<Type>* &copied_tree_root, 
                                   Node<Type>* other_tree_root) {
  if (other_tree_root == nullptr) {
    copied_tree_root = nullptr;
  } else {
    copied_tree_root = new Node<Type>;
    copied_tree_root->value = other_tree_root->val;
    copy_tree(copied_tree_root->left, other_tree_root->left);
    copy_tree(copied_tree_root->right, other_tree_root->right);
  }
}

template <class Type>
void binary_tree<Type>::inorder(Node<Type> *p) const {
  if (p != nullptr) {
    inorder(p->left);
    std::cout << inorder(p->val) << " ";
    inorder(p->right);
  }
}

template <class Type>
void binary_tree<Type>::preorder(Node<Type> *p) const {
  if (p != nullptr) {
    std::cout << inorder(p->val) << " ";
    inorder(p->left);
    inorder(p->right);
  }
}

template <class Type>
void binary_tree<Type>::postorder(Node<Type> *p) const {
  if (p != nullptr) {
    inorder(p->left);
    inorder(p->right);
    std::cout << inorder(p->val) << " ";
  }
}

// TODO []: assignment operator
template <class Type>
const binary_tree<Type>& binary_tree<Type>::operator=(const binary_tree<Type> &other_tree){}
//    int height(Node<Type> *p) const;
//    int max(int x, int y) const;
//    int node_count(Node<Type> *p) const;
//    int leaves_count(Node<Type> *p) const;
//binary_trees();
//maps();
//void linked_list();
//void graphs();

int main() {
  std::cout << "Welcome to the algorithm and data structure menu\n";

  char input;
  do {
    std::cout << "------------------------------------------------\n"
              << "1: Arrays\n"
              << "2: Maps\n"
              << "3: Linked list\n"
              << "4: Trees\n"
              << "5: Graphs\n"
              << "0: Exit\n"
              << "input: ";
    std::cin >> input;
    std::cout << '\n';
    switch (input) {
      case '1':
        arrays();
        break;
      case '2':
        //maps();
        break;
      case '3':
        //linked_list();
        break;
      case '4':
        //trees();
        break;
      case '5':
        //graphs();
        break;
      case '0':
        break;
      default:
        std::cerr << "Error: Invalid input. Please select number between 1-5\n";
        break;
    }
  } while (input != '0');
}
