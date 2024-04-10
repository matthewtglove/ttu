/**********************************************************************
	Title:		DriverForAVLTree.cpp
	Author:		April R Crockett
	Date:		Spring 2018
	Purpose:	A program that creates and uses an AVLTree object
**********************************************************************/
#include<iostream>
#include "AVLTree.h"
#include "TreeNode.h"
using namespace std;
 

int main()
{
    int choice, item;
    AVLTree avl;
	TreeNode* root = NULL;
	
    do
    {
        cout<<"\n---------------------"<<endl;
        cout<<"AVL Tree Implementation"<<endl;
        cout<<"\n---------------------"<<endl;
        cout<<"1.Insert Element into the tree"<<endl;
        cout<<"2.Display Balanced AVL Tree"<<endl;
        cout<<"3.InOrder traversal"<<endl;
        cout<<"4.PreOrder traversal"<<endl;
        cout<<"5.PostOrder traversal"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\n\nEnter value to be inserted: ";
            cin>>item;
            root = avl.insert(root, item);
            break;
        case 2:
            if (root == NULL)
            {
                cout<<"\n\nTree is Empty"<<endl;
                continue;
            }
            cout<<"\n\nBalanced AVL Tree:"<<endl;
            avl.display(root, 1);
            break;
        case 3:
            cout<<"\n\nInorder Traversal:"<<endl;
            avl.inorder(root);
            cout<<endl;
            break;
        case 4:
            cout<<"\n\nPreorder Traversal:"<<endl;
            avl.preorder(root);
            cout<<endl;
            break;
        case 5:
            cout<<"Postorder Traversal:"<<endl;
            avl.postorder(root);    
            cout<<endl;
            break;
        case 6:
            break;
        default:
            cout<<"Wrong Choice.  Choose 1 - 6."<<endl;
        }
    } while(choice != 6);
    return 0;
}