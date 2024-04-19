#include <iostream>
#include <cassert>
//Write a recursive function to implement the recursive algorithm of Exercise 16 (reversing the elements of an array between two indices). Also, write a program to test your function.

void reverse(int list[], int len, int lower, int upper) {
  assert(lower >= 0 && upper < len);
  if (lower >= upper) return;
  int temp = list[lower];
  list[lower] = list[upper];
  list[upper] = temp;
  reverse(list, len, lower + 1, upper - 1);
}

void print_array(int list[], int len) {
  for (int i = 0; i < len; i++) {
    std::cout << list[i] << " ";
  }
  std::cout << '\n';
}

int main() {
  int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  size_t len = sizeof(list) / sizeof(list[0]);
  int leftIndex, rightIndex;
  int test = 0;
  while (test < 3) {
    std::cout << "Enter start index to reverse (greater than 0): ";
    std::cin >> leftIndex;
    if (leftIndex >= 0 && leftIndex < len) {
      std::cout << "Enter right index to reverse (less than 9): ";
      std::cin >> rightIndex;
      if (rightIndex < len) {
	reverse(list, len, leftIndex, rightIndex);
	print_array(list, len);
	test++;
      } else {
	std::cout << "Right index must be greater than or equal to zero and less than or equal to nine\n";
      }
    } else {
      std::cout << "Left index must be greater than or equal to zero and less than or equal to nine\n";
    }
  }
}
