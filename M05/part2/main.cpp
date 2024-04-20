#include <iostream>
#include "binary-tree.h"
using namespace std;

int main() {
  binaryTreeType<int> tree;
  tree.insert(6);
  tree.insert(2);
  tree.insert(3);
  tree.insert(4);
  tree.insert(5);
  tree.insert(6);
  tree.insert(8);
  int leaves = tree.treeLeavesCount();

  cout << "Number of leaves in the binary tree: " << leaves << endl;

  return 0;
}

