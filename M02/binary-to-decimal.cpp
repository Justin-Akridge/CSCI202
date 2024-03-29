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
  //std::reverse(binary_number.begin(), binary_number.end());
  // instead of reversing string we can stack items then pop
  std::stack<int> bin_stk;
  for (auto &ch : binary_number) {
    bin_stk.push(ch - '0');
  }

  int decimal = 0;
  int weight = 0;
  while (!bin_stk.empty()) {
    int bit = bin_stk.top();
    decimal += binary_to_decimal(bit, weight);
    bin_stk.pop();
    ++weight;
  }
  std::cout << decimal << '\n';
}
