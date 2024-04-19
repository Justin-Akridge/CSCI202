#include <iostream>
#include <cassert>

class Stars {
public:
  void print_pattern(int stars) {
    if (stars == 0) return;
    print_stars(stars);
    print_pattern(stars - 1);
    print_stars(stars);
  }
private:
  void print_stars(int stars) {
    for (int i = 0; i < stars; i++) {
      std::cout << "*";
    }
    std::cout << '\n';
  }
};


int main() {
  Stars reg;
  int input;
  for (int i = 0; i < 3; i++) {
    std::cout << "Enter how lines for the pattern: ";
    std::cin >> input;
    reg.print_pattern(input);
  }
}
