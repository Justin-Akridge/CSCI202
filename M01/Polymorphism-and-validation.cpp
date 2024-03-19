#include <iostream>
#include <string>
#include <cassert>
#include <unordered_map>

using namespace std::string_literals;

class romanType {
public:
  romanType() : roman_numeral(""), decimal(0) {}
  romanType(std::string roman_numeral_) : roman_numeral(roman_numeral_) { convert_to_decimal(); }

  void convert_to_decimal() {
    if (this->roman_numeral.size() == 0) {
      std::cout << "No roman numeral provided\n";
      return;
    }

    int decimal_number = 0;
    int prev_dec = 0; 
    int curr_dec = 0;
    for (auto it = roman_numeral.rbegin(); it != roman_numeral.rend(); ++it) {
      prev_dec = curr_dec;
      curr_dec = conversion_table[toupper(*it)];
      if (curr_dec < prev_dec) decimal_number -= curr_dec;
      else decimal_number += curr_dec;
    }
    decimal = decimal_number;
  }

  void print_roman() const { std::cout << roman_numeral << '\n'; }
  void print_decimal() const { std::cout << decimal << '\n'; }

  void set_roman_literal(std::string s) {
    // this could be sped up with map
    std::string valid_chars = "MDCLXVI";
    for (auto &ch : s) {
      int found = valid_chars.find(ch);
      if (found == std::string::npos) {
        std::cout << "String: " << s <<  "contains invalid character [" << ch << "]";
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

int main() {
  romanType test1("MCXIV");
  assert(test1.get_decimal() == 1114);

  test1.set_roman_literal("CCCLIX");
  assert(test1.get_decimal() == 359);

  test1.set_roman_literal("MDCLXVI");
  assert(test1.get_decimal() == 1666);
}
