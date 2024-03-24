// Specification file for the CreatureBinaryTree class
#ifndef CREATUREBINARYTREE_H
#define CREATUREBINARYTREE_H

#include "Creature.h"

class CreatureBinaryTree
{
	private:
		struct TreeNode
		{
			Creature value;         // The value in the node
			TreeNode *left;    // Pointer to left child node
			TreeNode *right;   // Pointer to right child node
		};

		TreeNode *root;       // Pointer to the root node
		int numNodes;

		// Private member functions
		void insert(TreeNode *&, TreeNode *&);
		void destroySubTree(TreeNode *);
		void deleteNode(Creature, TreeNode *&);
		void makeDeletion(TreeNode *&);
		void saveToFile(TreeNode *) const;
		void fullDisplayInOrder(TreeNode *) const;
		void displayInOrder(TreeNode *) const;
		void displayPreOrder(TreeNode *) const;
		void displayPostOrder(TreeNode *) const;

	public:
		// Constructor
		CreatureBinaryTree()
		{ 
			root = NULL; 
			numNodes = 0;
		}

		// Destructor
		~CreatureBinaryTree()
		{ 
			destroySubTree(root); 
		}

		// Binary tree operations
		void insertNode(Creature);
		bool searchNode(Creature);
		void remove(Creature);
		
		void saveToFile() const
		{  
			saveToFile(root); 
		}

		void fullDisplayInOrder() const
		{  
			fullDisplayInOrder(root); 
		}
		
		void displayInOrder() const
		{  
			displayInOrder(root); 
		}

		void displayPreOrder() const
		{  
			displayPreOrder(root); 
		}

		void displayPostOrder() const
		{  
			displayPostOrder(root); 
		}
		
		int getNumNodes() const
		{
			return numNodes;
		}
		
		Creature getRootCreature() const
		{
			return root->value;
		}


};
#endif