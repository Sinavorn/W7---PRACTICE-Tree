#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <string.h>
#include "Node.h"
#include <cstdlib>

using namespace std;

class BinaryTree {
private:
    Node* root;

    //Exercise2
    void insertRandom(Node* node, int value) {
        int direction = rand() % 2; 
        if (direction == 0) {
            if (node->left != nullptr) {
                insertRandom(node->left, value);
            } else {
                node->left = new Node(value);
            }
        } else {
            if (node->right != nullptr) {
                insertRandom(node->right, value);
            } else {
                node->right = new Node(value);
            }
        }
    }
    int calculateHeight(Node* node) {
        if (node == nullptr) return 0;
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);
        return 1 + max(leftHeight, rightHeight);
    }
    void printTree(Node* node, string prefix, bool isLeft) {
        if (node != nullptr) {
            cout << prefix;
            cout << (isLeft ? "|- " : "|-- ");
            cout << node->data << endl;
            printTree(node->left, prefix + (isLeft ? "|   " : "    "), true);
            printTree(node->right, prefix + (isLeft ? "|   " : "    "), false);
        }
    }

public:
    BinaryTree(int value) {
        root = new Node(value);
    }
    void insertLeft(int value) {
        root->left = new Node(value);
    }
    void insertRight(int value) {
        root->right = new Node(value);
    }

    std::string inOrderTraverse() {
        std::string result = "";
        inOrder(root, result);
        return result;
    }
    std::string preOrderTraverse() {
        std::string result = "";
        preOrder(root, result);
        return result;
    }
    std::string postOrderTraverse() {
        std::string result = "";
        postOrder(root, result);
        return result;
    }

    Node* getroot() {
        return root;

    }

    //Exercise2
    BinaryTree() {
        root = nullptr;
    }
    void insert(int value) {
        if (root == nullptr) {
            root = new Node(value);
        } else {
            insertRandom(root, value);
        }
    }
    int getHeight() {
        return calculateHeight(root);
    }
    void printTree() {
        printTree(root, "", false);
    }
  
  //Exercise1
private:
     void inOrder(Node* node, std::string& result) {
        //your code here
        if(node==nullptr) return;
          inOrder(node ->left,result);
          result += std::to_string(node->data) + " ";
          inOrder(node->right,result);
            
    }
    void preOrder(Node* node, std::string& result) {
        //your code here
        if(node==nullptr) return;
          result += std::to_string(node->data) + " ";
          preOrder(node->left,result);
          preOrder(node->right,result);
        
    }
    void postOrder(Node* node, std::string& result) {
        //your code here
        if(node==nullptr) return;
          postOrder(node->left,result);
          postOrder(node->right,result);
          result += std::to_string(node->data) + " ";

    }
    
};

  //Exercise2
  

#endif // BINARYTREE_H

