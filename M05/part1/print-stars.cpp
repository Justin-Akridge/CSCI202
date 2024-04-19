#include <iostream>
#include <cassert>

void print_stars(int stars) {
  for (int i = 0; i < stars; i++) {
    std::cout << "*";
  }
  std::cout << '\n';
}

void print_pattern(int stars) {
  if (stars == 0) return;
  print_stars(stars);
  print_pattern(stars - 1);
  print_stars(stars);
}

int main() {
  int input;
  for (int i = 0; i < 3; i++) {
    std::cout << "Enter how lines for the pattern: ";
    std::cin >> input;
    print_pattern(input);
  }
}
