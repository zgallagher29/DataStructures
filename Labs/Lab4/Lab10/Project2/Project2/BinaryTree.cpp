#include <iostream>
#include <stack>
#include <fstream>
#include <vector>
#include <cstring>
#include "BinaryTree.h"
#include <cmath>//included for max in extra credit
#include "math.h"
#include <string>
using namespace std;

int
BinaryTree:: ComputeHeight(TreeNode *Root){
	if (Root == NULL){    //source: cracking the code interview book
		return -1;
	}
	return fmax(ComputeHeight(Root->Lchild), ComputeHeight(Root->Rchild)) + 1;
}

void 
BinaryTree::InsertNode(char * word){
	TreeNode *newNode,  // Pointer to a new node
		*nodePtr;
	nodePtr = NULL;// Pointer to traverse the tree
	newNode = new TreeNode;
	newNode->Data = word[0];
	newNode->Lchild = NULL;
	newNode->Rchild = NULL;
	int i = 0;
	Root = createNode(word[0]);

	if (!Root){  // Is the tree empty?
		Root = createNode(word[0]);
	}
	else{
		nodePtr = Root;
		while (nodePtr != NULL){
			for (i = 1; i < sizeof(word); i++){
				if (nodePtr->Data < word[i]){
					if (nodePtr->Lchild == NULL){
						nodePtr->Lchild = newNode;
						return;
					}
					break;
				}
				else if (nodePtr->Rchild == NULL){
					nodePtr->Rchild = newNode;
					break;
				}
				else{
					cout << "Duplicate" << endl;
				}
			}
		}
	}

}
int
BinaryTree::CountNodes(TreeNode*node){    //source:http://www.martinbroadhurst.com/articles/counting-nodes-in-a-binary-tree-recursively.html
	int count=0;
	if (node != NULL){
		count = 1 + CountNodes(node->Lchild) + CountNodes(node->Rchild);
	}
	return count;
}

TreeNode* 
BinaryTree::createNode(char val){
	cout <<"VAL="<< val << endl;
	TreeNode *Root = new TreeNode();
	Root->Data = NULL;
	Root->Data = val;
	Root->Lchild = NULL;
	Root->Rchild = NULL;
	return Root; 


}
char
BinaryTree::TraverseTree(char * sequence){
	return sequence[0];
}