#include <iostream>
#include <stack>
#include <fstream>
#include <vector>
#include <cstring>
#include "BinaryTree.h"
#include <cmath>//included for max in extra credit
#include "math.h"
#include <algorithm> 
using namespace std;


int
BinaryTree::ComputeHeight(TreeNode *node){ //source for this function came from cracking the code interview book. this function uses recursion

	if (!node) return -1;  //if the root is null then the tree doesnt get a height and it's the base case

	return 1 + max(ComputeHeight(node->Lchild), ComputeHeight(node->Rchild)); //compares the two heights and adds one
}

void BinaryTree::InsertNode(char * word){
	

	TreeNode *parent =Root;//to keep track of the parent node. I don't think it's used. I just kept it just in case
	TreeNode *nodePtr = Root; //used when switching between a new node and the current node
	TreeNode *newNode = new TreeNode(); //used for creating new nodes
	for (int i = 0; i !=10; i++) { //the size of the words are all ten. index starts at 0
		if (Root == NULL){ //this is the first case. it will do this for the vector words[0][0]. This will only be used once when creating the tree(hopefully)
			Root = createNode(word[i]);//sets the root to the value with the very first char
			nodePtr = Root;//intializes the variables
			parent = Root;//intializes the variables
		}

			if (word[i] == 'r') { //move r node to left side of the tree
				
				if (nodePtr->Lchild == NULL) { //do this if left node is empty
					TreeNode *newNode = new TreeNode();
					newNode = createNode(word[i]); //the new node will have its children set to null and r will placed as its value
					parent = nodePtr; //parent keeps track of previous node
					parent->Data = nodePtr->Data;
					nodePtr->Lchild = newNode; //since rs go on the left the left child gets the goods

					nodePtr = nodePtr->Lchild;
					nodePtr->Data = newNode->Data;

				}
				else {
					nodePtr = nodePtr->Lchild; //continue if the node is filled
				}
			}
			else if (word[i] == 'y') { //y inputs put into right node
				
			
				if (nodePtr->Rchild == NULL) { //do this if the right node is empty
					TreeNode *newNode = new TreeNode(); //create this if above is tree
					newNode = createNode(word[i]);//y goes into the newnode
					parent = nodePtr;
					parent->Data = nodePtr->Data;
					nodePtr->Rchild = newNode; //y goes into right ndode
					nodePtr = nodePtr->Rchild;
					nodePtr->Data = newNode->Data;
				

				}

				else {
					nodePtr = nodePtr->Rchild; //continue if not empty
				}
			}
		}

	}

int
BinaryTree::CountNodes(TreeNode*Root){//recursive function that will count the nodes in the tree 
	
	int count = 0; //intializing the count
	if (Root == NULL){    //source: cracking the code interview book
		return 0;							//when the code reaches the leaf node it will end and go and count all the nodes on the right
	}
	else{
		count++; //adds one for each non null node
		count = count + CountNodes(Root->Lchild); 
		count = count + CountNodes(Root->Rchild);
	}
}
TreeNode*
BinaryTree::createNode(char val){		//creates a new node to be added to the tree. intializes all the node's values
	TreeNode *Tmp;					
	Tmp = NULL;
	if (Tmp != NULL){
		delete Tmp;
	}
	Tmp = new TreeNode;		//creating new tree and intializing variables
	Tmp->Data = NULL; 
	Tmp->Lchild = NULL;
 	Tmp->Rchild = NULL;
	Tmp->Data = val;//the value passed by the function will be placed in node
	return Tmp;



}
char
BinaryTree::TraverseTree(char * sequence){  //this function is a iterative and evaluates the nodes in preorder notation 

	TreeNode *checkNode;
	stack<TreeNode *> nodeStack;
	nodeStack.push(Root);//root is always the first one in

	// pop all items one by one
	//right child is pushed first so left child can be evaluated first
	while (!nodeStack.empty())
	{
		// Pop the top item from stack, if the for loop ends before the loop goes through all the characters then it's not in the tree
		for (int x = 0; x < sizeof(sequence); x++){
			checkNode = nodeStack.top();
			if (checkNode->Data == sequence[x]){
				nodeStack.pop();

				// rchild goes first if there is data 
				if (checkNode->Rchild){
					nodeStack.push(checkNode->Rchild);
				}
				if (checkNode->Lchild){ //left child comes next so it will be on top if there is a left child 
					nodeStack.push(checkNode->Lchild);
				}

			}
			else{
				return 'N'; //returns n if the sequence doesnt match the data and will break out of the for loop
				break;
			}

		}
		return 'Y'; //only prints out if the every sequence char found a match



	}

}