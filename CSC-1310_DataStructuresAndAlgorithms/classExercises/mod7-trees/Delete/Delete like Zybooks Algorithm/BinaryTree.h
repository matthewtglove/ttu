// Specification file for the BinaryTree class
#ifndef BINARYTREE_H
#define BINARYTREE_H

class BinaryTree
{
	private:
		struct TreeNode
		{
			int value;         // The value in the node
			TreeNode *left;    // Pointer to left child node
			TreeNode *right;   // Pointer to right child node
		};

		TreeNode *root;       // Pointer to the root node

		void insert(TreeNode *&, TreeNode *&);
		void destroySubTree(TreeNode *);
		//void deleteNode(int, TreeNode *&);
		//void makeDeletion(TreeNode *&);
		void BSTRemove(TreeNode *, int);
		void displayInOrder(TreeNode *) const;
		void displayPreOrder(TreeNode *) const;
		void displayPostOrder(TreeNode *) const;

	public:

		BinaryTree()		// Constructor
		{ root = NULL; }

	
		~BinaryTree()	// Destructor
		{ destroySubTree(root); }

		void insertNode(int);
		bool searchNode(int);
		void remove(int);

		void displayInOrder() const
		{  displayInOrder(root); }

		void displayPreOrder() const
		{  displayPreOrder(root); }

		void displayPostOrder() const
		{  displayPostOrder(root); }
};
#endif