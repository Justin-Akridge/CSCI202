#include <iostream>
using namespace std;

class Node {
public:
  int key;
  Node *left;
  Node *right;
  int height;

  Node(int k) {
    key = k;
    left = nullptr;
    right = nullptr;
    height = 1;
  }
};

class AVLTree {
private:
  Node *root;

  int height(Node *node) {
    if (node == nullptr)
      return 0;
    return node->height;
  }

  int balanceFactor(Node *node) {
    if (node == nullptr)
      return 0;
    return height(node->left) - height(node->right);
  }

  Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
  }

  Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = max(height(x->left), height(x->right) + 1);
    y->height = max(height(y->left), height(y->right));

    return y;
  }

  Node* insert(Node* node, int key) {
    if (node == nullptr)
        return new Node(key);

    if (key < node->key)
      node->left = insert(node->left, key);
    else if (key > node->key)
      node->right = insert(node->right, key);
    else
      return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    if (balance > 1 && key < node->left->key)
      return rightRotate(node);

    if (balance < -1 && key > node->right->key)
      return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }
    return node;
  }

  void inorderTraversal(Node* root) {
    if (root != nullptr) {
      inorderTraversal(root->left);
      cout << root->key << " ";
      inorderTraversal(root->right);
    }
  } 

  void preorderTraversal(Node* root) {
    if (root != nullptr) {
      cout << root->key << " ";
      inorderTraversal(root->left);
      inorderTraversal(root->right);
    }
  } 

public:
  AVLTree() {
    root = nullptr;
  }

  void insert(int key) {
    root = insert(root, key);
  }

  void printInorder() {
    preorderTraversal(root);
    cout << endl;
  }
};

int main() {
    AVLTree avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);
    cout << "Inorder traversal of the AVL tree: ";
    avl.printInorder();
}


//        30
//    10      40
//        20     50
//            25   
