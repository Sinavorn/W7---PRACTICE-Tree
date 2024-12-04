#include <iostream>
#include "BinaryTree.h"
#include "Node.h"
#include"ctime"

using namespace std;

int main() {
    //1.	Create a binary Tree
    srand(static_cast <unsigned> (time(0))); 
    BinaryTree tree;

    //2.	Randomly generate 50 numbers
    for (int i = 0; i < 50; i++) {
        int randomValue = rand() % 100;

    //3.	Insert each number into the tree
        tree.insert(randomValue);
    }
    //4.    Print a tree result
        cout << "Binary Tree Structure:" << endl;
        tree.printTree();

    //5.    Challenge: Implement a function that returns the height of the tree
       int height = tree.getHeight();
       cout << "\nHeight of the Binary Tree: " << height << endl;

    return 0;
}