#include <iostream>
#include <stack>
#include <unordered_map>

class utils {
public:
  static void print_test_passed(std::string_view infix, std::string_view postfix) {
    std::cout << "Test[\033[32m\u2713\033[0m] assert(" << infix << " == " << postfix << ")\033[32m PASSED\033[0m\n";
  }

  static void print_test_failed(std::string_view infix, std::string_view postfix) {
    std::cout << "Test[\033[31m\u2717\033[0m] assert(" << infix << " != " << postfix << ")\033[31m FAILED\033[0m\n";
  }
};

class infix_converter {
public:
  infix_converter() {};
  infix_converter(const std::string infix_) : infix(infix_) { infix_to_postfix(infix_); }
  std::string get_infix() const { return infix; }
  std::string get_postfix() const { return postfix; }
  void set_infix(const std::string infix_) { infix = infix_; }

private:
  std::string infix;
  std::string postfix;

  int precedence(char op) {
    switch(op) {
      case '+':
      case '-':
        return 1;
      case '*':
      case '/':
        return 2;
      default:
        return 0;
    }
  }

  bool is_operator(char ch) {
    return (ch == '+' || ch == '-' || ch == '/' || ch == '*');
  }

  void infix_to_postfix(std::string infix) {
    std::string postfix_;
    std::stack<char> stk;

    for (char &ch : infix) {
      if (isalnum(ch)) {
        postfix_ += ch;
      } else if (ch == '(') {
        stk.push(ch);
      } else if (ch == ')') {
        while (!stk.empty() && stk.top() != '(') {
          postfix_ += stk.top();
          stk.pop();
        }
        stk.pop();
      } else if (is_operator(ch)) {
        while (!stk.empty() && precedence(stk.top()) >= precedence(ch)) {
          postfix_ += stk.top();
          stk.pop();
        }
        stk.push(ch);
      }
    }

    while (!stk.empty()) {
      postfix += stk.top();
      stk.pop();
    }
    postfix = postfix_;
  }
};

int main(int argc, char* argv[]) {
  // TESTS
  std::unordered_map<std::string, std::string> test_cases = {
    {"A + B - C", "AB+C-"},
    {"(A + B) * C", "AB+C*"},
    {"(A + B) * (C - D)", "AB+CD-*"},
    {"A + ((B + C) * (E - F) - G) / (H - I)", "ABC+EF-*G-HI-/+"},
    {"A + B * (C + D) - E / F * G + H", "ABCD++EF/G-H+"}
  };

  infix_converter infix_obj;
  for (auto &test_case : test_cases) {
    infix_obj.set_infix(test_case.first);
    if (infix_obj.get_postfix() == test_case.second) {
      utils::print_test_passed(test_case.first, test_case.second);
    } else {
      utils::print_test_passed(test_case.first, test_case.second);
    }
  }
}
