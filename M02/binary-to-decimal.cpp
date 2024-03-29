#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>

int main(int argc, char* argv[]) {
  auto binary_to_decimal = [](int bin, int weight) -> int {
    return bin * std::pow(2, weight);
  };
  std::string binary_number; 
  if (argc < 2) {
    std::cout << "Enter a binary number: ";
    std::cin >> binary_number;
  } else {
    std::string s(argv[1]);
    binary_number = s;
  }
  std::reverse(binary_number.begin(), binary_number.end());

  int decimal = 0;
  for (int i = 0; i < binary_number.size(); i++) {
    decimal += binary_to_decimal(binary_number[i] - '0', i);
  }
  std::cout << decimal << '\n';
}
