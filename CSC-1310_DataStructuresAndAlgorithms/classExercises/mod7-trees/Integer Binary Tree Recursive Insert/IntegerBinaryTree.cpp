// This program builds a binary tree with 5 nodes.
#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
	BinaryTree tree;

	cout << "\n\ninserting 5...\n";
	tree.insertNode(5);
	tree.displayInOrder();
	cout << "\n\ninserting 8...\n";
	tree.insertNode(8);
	tree.displayInOrder();
	cout << "\n\ninserting 3...\n";
	tree.insertNode(3);
	tree.displayInOrder();
	cout << "\n\ninserting 12...\n";
	tree.insertNode(12);
	tree.displayInOrder();
	cout << "\n\ninserting 9...\n";
	tree.insertNode(9);
	tree.displayInOrder();
	cout << "Done.\n";

	return 0;
}