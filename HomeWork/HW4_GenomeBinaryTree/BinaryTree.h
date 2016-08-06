/*
* BinaryTree.h

*
*  Created on: Apr 4, 2014
*      Author:zac gallagher
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
	int CountNodes(TreeNode*Root); //extra credit
	int ComputeHeight(TreeNode *node); //extra credit
	char TraverseTree(char * sequence);
	
};
