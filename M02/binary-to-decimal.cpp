#include <iostream>
#include <cmath>


void binary_to_decimal(long &binary_number, int &decimal, int& weight) {
  int bit;
  if (binary_number > 0) {
    bit = binary_number % 10;
    decimal = decimal + bit * static_cast<int>(std::pow(2.0, weight));
    binary_number /= 10;
    weight++;
    binary_to_decimal(binary_number, decimal, weight);
  }
}

int main(int argc, char* args[]) {
  int decimal = 0;
  int weight = 0;
  long binary_number;
  if (argc < 2) {
    std::cout << "Enter a binary number: ";
    std::cin >> binary_number;
    binary_to_decimal(binary_number, decimal, weight);
  } 
  std::cout << binary_number;
}
