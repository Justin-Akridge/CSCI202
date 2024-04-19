#include <iostream>
#include <cassert>
#include <vector>

class Reverse_array_type {
public:
  Reverse_array_type() { 
    list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  }
  void reverse(int lower, int upper) {
    assert(lower >= 0 && upper < list.size());
    if (lower >= upper) return;
    std::swap(list[lower], list[upper]);
    reverse(lower + 1, upper - 1);
  }

  int size() const {
    return list.size();
  }

  std::vector<int> get_list() const {
    return list;
  }

  void print_array() {
    for (const auto &num : list) {
      std::cout << num << " ";
    }
    std::cout << '\n';
  }
private:
  std::vector<int> list;
};

int main() {
  Reverse_array_type reg;
  int leftIndex, rightIndex;
  int test = 0;
  while (test < 3) {
    std::cout << "Enter start index to reverse (greater than 0): ";
    std::cin >> leftIndex;
    if (leftIndex >= 0 && leftIndex < reg.size()) {
      std::cout << "Enter right index to reverse (less than 9): ";
      std::cin >> rightIndex;
      if (rightIndex < reg.size()) {
        reg.reverse(leftIndex, rightIndex);
        reg.print_array();
        test++;
      } else {
        std::cout << "Right index must be greater than or equal to zero and less than or equal to nine\n";
      }
    } else {
      std::cout << "Left index must be greater than or equal to zero and less than or equal to nine\n";
    }
  }
}
