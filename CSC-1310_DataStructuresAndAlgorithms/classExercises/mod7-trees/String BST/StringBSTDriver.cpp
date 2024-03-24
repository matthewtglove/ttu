#include <iostream>
#include "StringBinaryTree.h"

using namespace std;

int main()
{
	StringBinaryTree tree;
	tree.insertNode("Spongebob Squarepants");
	tree.insertNode("Patrik Star");
	tree.insertNode("Plankton");
	tree.insertNode("Karen");
	tree.insertNode("Mr. Krabs");
	tree.insertNode("Sandy Cheeks");
	tree.insertNode("Gary");
	tree.insertNode("Mrs. Puff");
	tree.insertNode("Squilliam Fancyson");
	tree.insertNode("Pearl Krabs");
	
	tree.displayInOrder();
	
	cout << "\n\nRemoving Karen...\n\n";
	tree.removeNode("Karen");
	
	tree.displayInOrder();
	
	return 0;
}
