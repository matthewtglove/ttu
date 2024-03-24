// This program builds a binary tree with 5 nodes.
// The nodes are displayed with inorder, preorder,
// and postorder algorithms.
#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
   BinaryTree tree;

   // Insert some nodes.
   cout << "\n\nInserting nodes.\n";
   tree.insertNode(5);
   tree.insertNode(58);
   tree.insertNode(77);
   tree.insertNode(18);
   tree.insertNode(8);
   tree.insertNode(3);
   tree.insertNode(12);
   tree.insertNode(9);

   // Display inorder.
   cout << "Inorder traversal:\n";
   tree.displayInOrder();

   // Display preorder.
   cout << "\nPreorder traversal:\n";
   tree.displayPreOrder();

   // Display postorder.
   cout << "\nPostorder traversal:\n";
   tree.displayPostOrder();
   return 0;
}