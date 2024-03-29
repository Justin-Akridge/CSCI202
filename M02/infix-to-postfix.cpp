#include <iostream>
#include <stack>


//infix to posfix expression
//
int main(int argc, char* argv[]) {
  std::string infix;
  if (argv < 2) {
    std::cout << "Enter an expression: ";
    std::cin >> infix;
  } else {
    string temp(argv[1]);
    infix = temp;
  }

  std::string postifx;
  std::stack<char> stk;

}
