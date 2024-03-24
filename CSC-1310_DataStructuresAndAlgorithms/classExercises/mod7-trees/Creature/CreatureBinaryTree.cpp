// Implementation file for the IntBinaryTree class
#include <iostream>
#include "CreatureBinaryTree.h"
using namespace std;

//*************************************************************
// insert accepts a TreeNode pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by  *
// the TreeNode pointer. This function is called recursively. *
//*************************************************************

void CreatureBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
   if (nodePtr == NULL)
      nodePtr = newNode;                  // Insert the node.
   else if (newNode->value.getName() < nodePtr->value.getName())
      insert(nodePtr->left, newNode);     // Search the left branch
   else 
      insert(nodePtr->right, newNode);    // Search the right branch
}

//**********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function.                   *
//**********************************************************

void CreatureBinaryTree::insertNode(Creature newCreature)
{
	TreeNode *newNode = NULL;	// Pointer to a new node.

	if(this->searchNode(newCreature))
	{
		cout << "\nI\'m sorry.  " << newCreature.getName() << " is already in the zoo and therefore will not be added twice!\n";
	}
	else{
		// Create a new node and store num in it.
		newNode = new TreeNode;
		newNode->value = newCreature;
		newNode->left = newNode->right = NULL;

		// Insert the node.
		insert(root, newNode);
		
		//increment numNodes
		numNodes++;

		cout << "\nThe " << newCreature.getName() << " has been added to the zoo!\n";
	}   
}

//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree.                   *
//***************************************************

void CreatureBinaryTree::destroySubTree(TreeNode *nodePtr)
{
   if (nodePtr)
   {
      if (nodePtr->left)
         destroySubTree(nodePtr->left);
      if (nodePtr->right)
         destroySubTree(nodePtr->right);
      delete nodePtr;
   }
}
   
//***************************************************
// searchNode determines if a value is present in   *
// the tree. If so, the function returns true.      *
// Otherwise, it returns false.                     *
//***************************************************

bool CreatureBinaryTree::searchNode(Creature targetCreature)
{
   TreeNode *nodePtr = root;

   while (nodePtr)
   {
      if (nodePtr->value.getName() == targetCreature.getName())
         return true;
      else if (targetCreature.getName() < nodePtr->value.getName())
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return false;
}

//**********************************************
// remove calls deleteNode to delete the       *
// node whose value member is the same as num. *
//**********************************************

void CreatureBinaryTree::remove(Creature targetCreature)
{
   deleteNode(targetCreature, root);
   numNodes--;
}


//********************************************
// deleteNode deletes the node whose value   *
// member is the same as num.                *
//********************************************

void CreatureBinaryTree::deleteNode(Creature targetCreature, TreeNode *&nodePtr)
{
   if (targetCreature.getName() < nodePtr->value.getName())
      deleteNode(targetCreature, nodePtr->left);
   else if (targetCreature.getName() > nodePtr->value.getName())
      deleteNode(targetCreature, nodePtr->right);
   else
      makeDeletion(nodePtr);
}


//***********************************************************
// makeDeletion takes a reference to a pointer to the node  *
// that is to be deleted. The node is removed and the       *
// branches of the tree below the node are reattached.      *
//***********************************************************

void CreatureBinaryTree::makeDeletion(TreeNode *&nodePtr)
{
   // Define a temporary pointer to use in reattaching
   // the left subtree.
   TreeNode *tempNodePtr = NULL;

   if (nodePtr == NULL)
      cout << "Cannot delete empty node.\n";
   else if (nodePtr->right == NULL)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left;   // Reattach the left child
      delete tempNodePtr;
   }
   else if (nodePtr->left == NULL)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;  // Reattach the right child
      delete tempNodePtr;
   }
   // If the node has two children.
   else
   {
      // Move one node the right.
      tempNodePtr = nodePtr->right;
      // Go to the end left node.
      while (tempNodePtr->left)
         tempNodePtr = tempNodePtr->left;
      // Reattach the left subtree.
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      // Reattach the right subtree.
      nodePtr = nodePtr->right;
      delete tempNodePtr;
   }
}

//****************************************************************
// The saveToFile member function prints (to file) the full creature data    
// in the subtree pointed to by nodePtr, via inorder traversal.  
//****************************************************************
void CreatureBinaryTree::saveToFile(TreeNode *nodePtr) const
{
	if (nodePtr)
	{		
		saveToFile(nodePtr->left);
		nodePtr->value.printCreatureToFile("savedCreatures.txt");
		saveToFile(nodePtr->right);		
	}
}

//****************************************************************
// The fullDisplayInOrder member function displays the full creature data    
// in the subtree pointed to by nodePtr, via inorder traversal.  
//****************************************************************
void CreatureBinaryTree::fullDisplayInOrder(TreeNode *nodePtr) const
{	
	int counter = 0;
	if (nodePtr)
	{
		fullDisplayInOrder(nodePtr->left);
		cout << "------------------------------------------------------------------------" << endl;
		nodePtr->value.printCreature();
		fullDisplayInOrder(nodePtr->right);		
	}
}

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via inorder traversal.  *
//****************************************************************

void CreatureBinaryTree::displayInOrder(TreeNode *nodePtr) const
{
	int counter = 0;
	
	if (nodePtr)
	{
		displayInOrder(nodePtr->left);
		cout << counter+1 << ".\t" << nodePtr->value.getName() << endl;
		displayInOrder(nodePtr->right);
		counter++;
	}
}

//****************************************************************
// The displayPreOrder member function displays the values       *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//****************************************************************

void CreatureBinaryTree::displayPreOrder(TreeNode *nodePtr) const
{
	int counter = 0;
	if (nodePtr)
	{
		cout << counter+1 << ".\t" << nodePtr->value.getName() << endl;
		displayPreOrder(nodePtr->left);     
		displayPreOrder(nodePtr->right);
		counter++;
	}
}

//****************************************************************
// The displayPostOrder member function displays the values      *
// in the subtree pointed to by nodePtr, via postorder traversal.*
//****************************************************************

void CreatureBinaryTree::displayPostOrder(TreeNode *nodePtr) const
{
	int counter = 0;
	if (nodePtr)
	{
		displayPostOrder(nodePtr->left);    
		displayPostOrder(nodePtr->right);
		cout << counter+1 << ".\t" << nodePtr->value.getName() << endl;
		counter++;
	}
}