// Implementation file for the BinaryTree class
#include <iostream>
#include "BinaryTree.h"
using namespace std;

//**********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function.                   *
//**********************************************************

void BinaryTree::insertNode(int num)
{
   TreeNode *newNode = NULL;	// Pointer to a new node.

   // Create a new node and store num in it.
   newNode = new TreeNode;
   newNode->value = num;
   newNode->left = newNode->right = NULL;
   
   // Insert the node.
   insert(root, newNode);
}

//*************************************************************
// insert accepts a TreeNode pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by  *
// the TreeNode pointer. This function is called recursively. *
//*************************************************************

void BinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
   if (nodePtr == NULL)
      nodePtr = newNode;                  // Insert the node.
   else if (newNode->value < nodePtr->value)
      insert(nodePtr->left, newNode);     // Search the left branch
   else 
      insert(nodePtr->right, newNode);    // Search the right branch
}



//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree.                   *
//***************************************************

void BinaryTree::destroySubTree(TreeNode *nodePtr)
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

bool BinaryTree::searchNode(int num)
{
   TreeNode *nodePtr = root;

   while (nodePtr)
   {
      if (nodePtr->value == num)
         return true;
      else if (num < nodePtr->value)
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

void BinaryTree::remove(int num)
{
   BSTRemove(root, num);
}

//***********************************************************************************
void BinaryTree::BSTRemove(TreeNode* root, int key) {
	TreeNode* par = NULL; //parent
	TreeNode* suc = NULL; //successor
	int copy;
	
	TreeNode* cur = root;
	
	while (cur != NULL) { // Our current node is not NULL
		if (cur->value == key) { // Node found 
			if (!cur->left && !cur->right)//leaf node is being deleted
			{  	//make the parent node point to null
				if (!par) // Node is root
					root = NULL;
				else if (par->left == cur) 
					par->left = NULL;
				else
					par->right = NULL;
			}
			else if (cur->left && !cur->right)// Remove node with only left child 
			{    
				if (!par) // Node is root
					root = cur->left;
				else if (par->left == cur) 
					par->left = cur->left;
				else
					par->right = cur->left;
			}
			else if (!cur->left && cur->right)  // Remove node with only right child
			{   
				if (!par) // Node is root
					root = cur->right;
				else if (par->left == cur) 
					par->left = cur->right;
				else
					par->right = cur->right;
			}
			else // Remove node with two children
			{	
				// Find successor (leftmost child of right subtree)
				suc = cur->right;
				while (suc->left != NULL)
					suc = suc->left;
				
				copy = suc->value; //Create copy of suc's data
			
				BSTRemove(root, suc->value); // Remove successor
				
				cur->value = copy;//Assign cur's data with successorData
			
			}
			return; // Node found and removed
		}
		else if (cur->value < key) { // Search right
			par = cur;
			cur = cur->right;
		}
		else {                     // Search left
			par = cur;
			cur = cur->left;
		}
	}
	return; // Node not found
}

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via inorder traversal.  *
//****************************************************************

void BinaryTree::displayInOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
	  //cout << "\nLeft, nodePtr->left is " << nodePtr->left;
      displayInOrder(nodePtr->left);
	  //cout << "\nNode";
      cout << nodePtr->value << endl;
	  //cout << "\nRight, nodePtr->right is " << nodePtr->right;
      displayInOrder(nodePtr->right);
   }
}

//****************************************************************
// The displayPreOrder member function displays the values       *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//****************************************************************

void BinaryTree::displayPreOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      cout << nodePtr->value << endl;
      displayPreOrder(nodePtr->left);     
      displayPreOrder(nodePtr->right);
   }
}

//****************************************************************
// The displayPostOrder member function displays the values      *
// in the subtree pointed to by nodePtr, via postorder traversal.*
//****************************************************************

void BinaryTree::displayPostOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      displayPostOrder(nodePtr->left);    
      displayPostOrder(nodePtr->right);
      cout << nodePtr->value << endl;
   }
}