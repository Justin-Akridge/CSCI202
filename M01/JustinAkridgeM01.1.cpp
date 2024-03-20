/*
 * Justin Akridge
 * 03/19/2024
 * Roman numeral converter
 * Program: This file contains the romanType. The romanType allows roman_numerals
 * to be converted to decimal numbers.
 */

#include <iostream>
#include <string>
#include <string_view>
#include <cassert>
#include <unordered_map>

namespace {
class romanType {
public:
  romanType() : roman_numeral(""), decimal(0) {}
  romanType(std::string_view roman_numeral_) : roman_numeral(roman_numeral_) { convert_to_decimal(); }

  void convert_to_decimal() {
    if (this->roman_numeral.size() == 0) {
      std::cout << "No roman numeral provided\n";
      return;
    }

    int running_sum = 0;
    int prev_num = 0; 
    int curr_num = 0;
    for (auto it = roman_numeral.rbegin(); it != roman_numeral.rend(); ++it) {
      prev_num = curr_num;
      curr_num = conversion_table[toupper(*it)];
      if (curr_num < prev_num) running_sum -= curr_num;
      else running_sum += curr_num;
    }
    this->decimal = running_sum;
  }

  void print_roman() const { std::cout << roman_numeral << '\n'; }
  void print_decimal() const { std::cout << decimal << '\n'; }

  void set_roman_literal(std::string_view s) {
    // This could sped this up with a hash O(1) lookup 
    std::string valid_chars = "MDCLXVI";
    for (auto &ch : s) {
      int found = valid_chars.find(ch);
      if (found == std::string::npos) {
        std::cout << "String: " << s <<  "contains an invalid character [" << ch << "]";
        return;
      }
    }
    roman_numeral = s; 

    convert_to_decimal();
  }

  int get_decimal() const { return decimal; }

private:
  std::unordered_map<char, int> conversion_table {
    { 'M', 1000 },
    { 'D', 500  },
    { 'C', 100  },
    { 'L', 50   },
    { 'X', 10   },
    { 'V', 5    },
    { 'I', 1    },
  };
  std::string roman_numeral;
  int decimal;
};
}


class utils {
public:
  static void print_test_passed() {
    std::cout << "Test[";
    std::cout << "\033[32m";
    std::cout << "\u2713";
    std::cout << "\033[0m"; 
    std::cout << "]";
    std::cout << " assert(MCXIV == 1114) ";
    std::cout << "\033[32mPASSED\033[0m";
    std::cout << "\033[0m\n"; 
  }

  static void print_test_failed() {
    std::cout << "Test[";
    std::cout << "\033[31m";
    std::cout << "\u2717";
    std::cout << "\033[0m";
    std::cout << "]";
    std::cout << " assert(MCXIV == 1114) ";
    std::cout << "\033[31mFAILED\033[0m\n";
  }
};

int main() {
  romanType test1("MCXIV");
  if (test1.get_decimal() == 1114) utils::print_test_passed();
  else utils::print_test_failed();
  
  
  test1.set_roman_literal("CCCLIX");
  if (test1.get_decimal() == 359) utils::print_test_passed();
  else utils::print_test_failed();

  test1.set_roman_literal("MDCLXVI");
  if (test1.get_decimal() == 1666) utils::print_test_passed();
  else utils::print_test_failed();
}
