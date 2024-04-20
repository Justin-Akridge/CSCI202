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
  tree.inorderTraversal();
  cout << "\nNumber of leaves in the binary tree: " << leaves << "\n\n";

  tree.insert(11);
  tree.insert(21);
  tree.insert(11);
  tree.insert(23);
  tree.insert(44);
  leaves = tree.treeLeavesCount();
  tree.inorderTraversal();
  cout << "\nNumber of leaves in the binary tree: " << leaves << "\n\n";

  tree.insert(32);
  tree.insert(35);
  tree.insert(49);
  tree.insert(51);
  tree.insert(23);
  leaves = tree.treeLeavesCount();
  tree.inorderTraversal();
  cout << "\nNumber of leaves in the binary tree: " << leaves << endl;
}
