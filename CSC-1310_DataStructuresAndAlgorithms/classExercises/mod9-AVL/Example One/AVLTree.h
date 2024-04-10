/**********************************************************************
	Title:		AVLTree.h
	Author:		April R Crockett
	Date:		Spring 2018
	Purpose:	A class to implement the AVL Balanced Binary Search
				tree data structure.
**********************************************************************/

#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <iomanip>
#include "TreeNode.h"

using namespace std;

class AVLTree
{
	private:
	
		TreeNode* root;
		int numNodes;
		
		/*
			destroyAllNodes:	removes all nodes in the whole tree
								Uses a recursive algorithm
		*/
		void destroyAllNodes(TreeNode* nodePtr)
		{
			if(nodePtr)
			{
				if(nodePtr->getLeft() != NULL)
					destroyAllNodes(nodePtr = nodePtr->getLeft());
				if(nodePtr->getRight() != NULL)
					destroyAllNodes(nodePtr = nodePtr->getRight());
				delete nodePtr;
			}
		}
		
    public:
		AVLTree()
		{
			root = NULL;
			numNodes = 0;
		}
		~AVLTree()
		{
			destroyAllNodes(root);
		}
        int height(TreeNode *);
        int diff(TreeNode *);
		
        TreeNode *r_rotation(TreeNode *);
        TreeNode *l_rotation(TreeNode *);
        TreeNode *lr_rotation(TreeNode *);
        TreeNode *rl_rotation(TreeNode *);
		
        TreeNode* balance(TreeNode *);
		
        TreeNode* insert(TreeNode*, int);
        void display(TreeNode *, int);
        void inorder(TreeNode *);
        void preorder(TreeNode *);
        void postorder(TreeNode *);

};
 
/*	height:  Find the height of a node and return it	*/
int AVLTree::height(TreeNode *temp) 
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height(temp->getLeft());
        int r_height = height(temp->getRight());
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
 
/*	diff:  Find the HEIGHT DIFFERENCE between the left & right subtrees */
int AVLTree::diff(TreeNode *temp)
{
    int l_height = height(temp->getLeft());
    int r_height = height(temp->getRight());
    int b_factor= l_height - r_height;
    return b_factor;
}
 
/*	l_rotation:  Perform LEFT ROTATION on this parent node	*/              
TreeNode *AVLTree::l_rotation(TreeNode *parent)
{
    TreeNode *temp;
    temp = parent->getRight();
	
    parent->setRight(temp->getLeft()); //SWITCHING TEAMS (if node exists, NULL otherwise)
    temp->setLeft(parent);  //new parent node (move old parent to left)
	
    return temp;
}

/*	r_rotation:  Perform RIGHT ROTATION on this parent node	*/
TreeNode *AVLTree::r_rotation(TreeNode *parent)
{
    TreeNode *temp;
    temp = parent->getLeft();
    parent->setLeft(temp->getRight()); //SWITCHING TEAMS
    temp->setRight(parent); //new parent node (move old parent to right)
    return temp;
}
 
/*	lr_rotation:  Perform LEFT-RIGHT ROTATION on this parent node	*/
TreeNode *AVLTree::lr_rotation(TreeNode *parent)
{
    TreeNode *temp;
    temp = parent->getLeft();
    parent->setLeft(l_rotation(temp));
    return r_rotation(parent);
}
 
/*	rl_rotation:  Perform RIGHT-LEFT ROTATION on this parent node	*/
TreeNode *AVLTree::rl_rotation(TreeNode *parent)
{
    TreeNode *temp;
    temp = parent->getRight();
    parent->setRight(r_rotation(temp));
    return l_rotation(parent);
}
 
/*	
	balance:	Balance the Tree into an AVL tree	
*/
TreeNode *AVLTree::balance(TreeNode *temp)
{
    int bal_factor = diff (temp);
    if (bal_factor > 1)
    {
        if (diff(temp->getLeft()) > 0)  // 2, 1  RIGHT
		{
            temp = r_rotation(temp);
			cout << "\nRIGHT rotation";
		}
        else							// 2, -1 LEFT-RIGHT
		{
            temp = lr_rotation(temp);
			cout << "\nLEFT-RIGHT rotation";
		}
    }
    else if (bal_factor < -1)
    {
        if (diff (temp->getRight()) > 0) // -2, 1 RIGHT-LEFT
		{
            temp = rl_rotation(temp);
			cout << "\nRIGHT-LEFT rotation";
		}
        else 							// -2, -1 LEFT
		{
            temp = l_rotation(temp);
			cout << "\nLEFT Rotation";
		}
    }
    return temp;
}
 
/*	
	insert:	Insert a new node into the AVL tree with value	
			Uses recursive algorithm

*/
TreeNode* AVLTree::insert(TreeNode* root, int num) 
{
	//create a new TreeNode with given value
	TreeNode *newNode = new TreeNode;
	newNode->setValue(num);
	
	
	//figure out where this node should go!
	
	//should it be the root?
	if(root == NULL)
	{
		root = newNode;
		return root;
	}
	//otherwise, it is not the root...find the location
	TreeNode* cur = root;
	while (cur != NULL) 
	{
		if(newNode->getValue() < cur->getValue())	//move to the left subtree
		{
			if (cur->getLeft() == NULL)		//there is nothing on left of cur
			{
				cur->setLeft(newNode);		//so insert the new node here
				cur = NULL;				//this will allow us to exit the while loop (because we are done)
			}
			else						//there is something on left 
				cur = cur->getLeft();			//travel to left node & make it new cur
		}
		else							//move to the right subtree 
		{
			if (cur->getRight() == NULL) 	//there is nothing on the right of cur
			{
				cur->setRight(newNode);		//so insert the new node here
				cur = NULL;				//this will allow us to exit the while loop (because we are done)
			}
			else
				cur = cur->getRight();
		}
	}

	//now the new node is already inserted so 
	//the next step is to make sure tree is balanced
	root = balance(root);
	
	return root;
}

 
/*	
	display:  	Display the AVL Tree	
				Uses recursive algorithm
*/
void AVLTree::display(TreeNode *ptr, int level)
{
    int i;
    if (ptr!=NULL)
    {
        display(ptr->getRight(), level + 1);
        printf("\n");
        for (i = 0; i < level && ptr != root; i++)
            cout<<"        ";
        cout<<ptr->getValue();
        display(ptr->getLeft(), level + 1);
    }
}
 
/*	inorder:  print the tree node values using in-order traversal 	*/
void AVLTree::inorder(TreeNode *tree)
{
    if (tree == NULL)
        return;
    inorder (tree->getLeft());
    cout<<tree->getValue()<<"  ";
    inorder (tree->getRight());
}

/*	preorder:  print the tree node values using pre-order traversal 	*/
void AVLTree::preorder(TreeNode *tree)
{
    if (tree == NULL)
        return;
    cout<<tree->getValue()<<"  ";
    preorder (tree->getLeft());
    preorder (tree->getRight());
 
}
 
/*	postorder:  print the tree node values using post-order traversal 	*/
void AVLTree::postorder(TreeNode *tree)
{
    if (tree == NULL)
        return;
    postorder ( tree->getLeft() );
    postorder ( tree->getRight());
    cout<<tree->getValue()<<"  ";
}

#endif