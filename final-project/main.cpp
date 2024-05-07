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
    size_of_array = 20;
    srand(time(NULL));
    for (int i = 0; i <= last_index; i++) {
      arr[i] = rand() % 100;
    }
  }

  void reset_array() {
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

    reset_array();
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

    std::cout << "[]";

    reset_array();
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
  }

  void selection_sort() {
    // this may need to be initialized
    //initialize();
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

  // TODO []: Do this!
  void bubble_sort() {
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

  int get_last_index() const {
    return last_index;
  }

private:
  int last_index;
  int size_of_array;
  int *arr;
};


int main() {
  Array arr;
  arr.initialize();
  arr.print();
  arr.quick_sort(0, arr.get_last_index());
  arr.print();

}

void arrays() {
  Array array;
  std::cout << "An array is a data structure consisting of a collection of elements, of same memory size, each identified by at least one array index or key.\n"
            << "There are several different algorithms that can be performed on an array.\n"
            << "Select the algorithm you would like to see.\n"
            << "1. Push: \n"
            << "2. Pop: \n"
            << "3. Merge sort: \n"
            << "4. Bubble sort: \n"
            << "5. Quick sort: \n"
            << "6. Selection sort: \n"
            << "input: ";
  char input;
  std::cin >> input;
  switch (input) {
    case '1':
      array.push();
      break;
    case '2':
      //pop();
      break;
    case '3':
      //merge_sort();
      break;
    case '4':
      //bubble_sort();
      break;
    case '5':
      //quick_sort();
      break;
    case '6':
      //selection_sort();
      break;
    default:
      std::cerr << "Error: Invalid input. Please select number between 1-5\n";
      break;
  }
  // need to reset array to initialization to visualize next operation if requested
  //array.initialize;

}
//void maps();
//void linked_list();
//void trees();
//void graphs();

//int main() {
//  std::cout << "Welcome to the algorithm and data structure menu\n";
//
//  char input;
//  do {
//    std::cout << "------------------------------------------------\n"
//              << "1: Arrays\n"
//              << "2: Maps\n"
//              << "3: Linked list\n"
//              << "4: Trees\n"
//              << "5: Graphs\n"
//              << "0: Exit\n"
//              << "input: ";
//    std::cin >> input;
//    std::cout << '\n';
//    switch (input) {
//      case '1':
//        //arrays();
//        break;
//      case '2':
//        //maps();
//        break;
//      case '3':
//        //linked_list();
//        break;
//      case '4':
//        //trees();
//        break;
//      case '5':
//        //graphs();
//        break;
//      case '0':
//        break;
//      default:
//        std::cerr << "Error: Invalid input. Please select number between 1-5\n";
//        break;
//    }
//  } while (input != '0');
//}
