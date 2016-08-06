/*
* BinaryTree.h

*
*  Created on: Apr 4, 2014
*      Author: msaenz
*/

#include <iostream>

using namespace std;

class TreeNode {
public:
	
	char Data;
	TreeNode *Lchild;
	TreeNode *Rchild;
};

class BinaryTree {
public:
	TreeNode *Root;
public:
	BinaryTree() {
		Root = NULL;
	}
	void InsertNode(char * word);
	TreeNode* createNode(char val);
	int CountNodes(TreeNode*node); //extra credit
	int ComputeHeight(TreeNode*  Root); //extra credit
	char TraverseTree(char * sequence);
};

