#ifndef STRINGBINARYTREE_H
#define STRINGBINARYTREE_H

#include <iostream>
using namespace std;

class StringBinaryTree
{
	private:
		struct TreeNode
		{
			string value;
			TreeNode* left;
			TreeNode* right;
		};
		
		TreeNode* root;
		
		void insert(TreeNode*&, TreeNode*&);
		void remove(TreeNode*&, string);
		void makeDeletion(TreeNode*&);
		void displayInOrder(TreeNode*) const;
	
	public:
	
		StringBinaryTree()
		{
			root = NULL;
		}
		
		void insertNode(string nodeStringValue)
		{
			//create a new node
			TreeNode* newNode = new TreeNode;
			newNode->value = nodeStringValue;
			newNode->left = newNode->right = NULL;
			
			//now insert in correct location in tree
			insert(root, newNode);
		}
		
		void removeNode(string nodeStringValue)
		{
			remove(root, nodeStringValue);
		}
		
		void displayInOrder()
		{
			displayInOrder(root);
		}
};

void StringBinaryTree::insert(TreeNode* &nodePtr, TreeNode* &newNode)
{
	if(nodePtr == NULL)
		nodePtr = newNode;
	else if(newNode->value < nodePtr->value)  //newNode needs to be inserted in the left subtree
		insert(nodePtr->left, newNode);
	else //newNode will be inserted in the right subtree
		insert(nodePtr->right, newNode);
}

void StringBinaryTree::remove(TreeNode* &nodePtr, string nodeStringValue)
{
	if(nodeStringValue < nodePtr->value) //string is in left subtree
		remove(nodePtr->left, nodeStringValue);
	else if(nodeStringValue > nodePtr->value) //string is in right subtree
		remove(nodePtr->right, nodeStringValue);
	else
		makeDeletion(nodePtr); //either null or the one to remove
}

void StringBinaryTree::makeDeletion(TreeNode* &nodePtr)
{
	TreeNode* tempNodePtr;
	
	//what if root?
	if(nodePtr == NULL) 
		cout << "Cannot delete empty node.\n";
	else if(nodePtr->right == NULL) //there is no child on the right
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left; //reattach left child
		delete tempNodePtr;
	}
	else if(nodePtr->left == NULL) //there is no child on the left
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
	else //the node has two children
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

void StringBinaryTree::displayInOrder(TreeNode* nodePtr) const   //LNR
{
	if(nodePtr != NULL)
	{
		displayInOrder(nodePtr->left); //left
		cout << nodePtr->value << "\n"; //print current node
		displayInOrder(nodePtr->right); //right
	}
}
#endif