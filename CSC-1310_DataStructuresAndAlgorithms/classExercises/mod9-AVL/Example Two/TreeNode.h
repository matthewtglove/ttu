/**********************************************************************
	Title:		TreeNode.h
	Author:		April R Crockett
	Date:		Spring 2018
	Purpose:	A class describing a single node in a Binary Tree
**********************************************************************/

#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using namespace std;

class TreeNode
{
	private:
		int value;
		TreeNode *left;
		TreeNode *right;
		
	public:
		TreeNode()
		{
			value = 0;
			left = NULL;
			right = NULL;
		}
		~TreeNode()
		{
			cout << "\nDeleted a node.";
		}
		int getValue()
		{
			return value;
		}
		TreeNode* getLeft()
		{
			return left;
		}
		TreeNode* getRight()
		{
			return right;
		}
		void setValue(int num)
		{
			value = num;
		}
		void setLeft(TreeNode* nodePtr)
		{
			left = nodePtr;
		}
		void setRight(TreeNode* nodePtr)
		{
			right = nodePtr;
		}	
};

#endif