// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>
template<typename T>
class BST {
 private:
  struct Node {
    T value;
    int count;
    Node* left;
    Node* right;
  };
  Node* root;
  int searchNode(Node* root, T value) {
    if (root == nullptr) return 0;
    else if (root->value == value) return root->count;
    else if (value < root->value) return searchNode(root->left, value);
    else if (value > root->value) return searchNode(root->right, value);
  }
  int getDepth(Node* root) {
    if (!root) return 0;
    else
      return std::max(getDepth(root->left), getDepth(root->right)) + 1;
  }

 public:
  BST() : root(nullptr) {}
  void add(T value) {
    root = add_word(root, value);
  }
  Node* add_word(Node* temp, T val) {
  if (temp == nullptr) {
    temp = new Node;
    temp->value = val;
    temp->count = 1;
    temp->left = nullptr;
    temp->right = nullptr;
  } else if (temp->value > val) {
    temp->left = add_word(temp->left, val);
  } else if (temp->value < val) {
    temp->right = add_word(temp->right, val);
  } else {
    temp->count++;
  }
    return temp;
  }
  int depth() {
    return getDepth(root) - 1;
  }
  int search(T value) {
    int temp = searchNode(root, value);
    if (temp != nullptr) return temp;
    else
      return 0;
  }
};
#endif  // INCLUDE_BST_H_
