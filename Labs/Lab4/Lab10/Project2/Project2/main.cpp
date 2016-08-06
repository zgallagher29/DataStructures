/*
* main.cpp
*
*  Created on: Apr 4, 2014
*      Author: msaenz
*/

#include <iostream>
#include <stack>
#include <fstream>
#include <vector>
#include <cstring>
#include "BinaryTree.h"
#include <string>

using namespace std;

bool get_words(char * file_name, vector<string> &w, char type);
bool get_reads(char * file_name, vector<string> &r, char type);
bool write_vector_to_screen(vector<string> v);
bool write_vector_to_file(vector<string> v, char * file_name);

int main() {
	char input;
	char* file=NULL;
	cout << "Enter B or Q for file parsing user: ";
	cin >> input;
	input = tolower(input);
	while (input != 'b' && input != 'q') {
		cout
			<< "Did not understand your input please pick b or q for parsing genome: "
			<< endl;
		cin >> input;
	}

	if (input == 'b'){
		file = "genome_file.txt";
	}
	vector<string> words;
	char letterType = 'B';
	get_words(file, words, letterType);
	char* w = NULL;
	//Do Work Herec
	get_reads(file, words, letterType);
	cout << words[0] << endl;
	cout << words[10] << endl;
	for (int i = 0; i < sizeof(words); i++){
		
		BinaryTree* newTree = new BinaryTree();
		char *w = new char[words[i].size() + 1];
		memcpy(w, words[i].c_str(), words[i].size());
		newTree->InsertNode(w);
		
		delete newTree;
	}
	//write_vector_to_screen(words);

	system("pause");
	return 1;
}


/*******************************************************************************
This function takes the genome file name to read and reads all overlapping
words of size 10 that are present in the file and stores each word in a vector.
The vector is passed to this function as a parameter -- by reference such
that the calling function has access to the vector of words.
Type='B' means you are doing a binary tree. Type='Q' means you are doing
the quartenary tree. This function will translate the file such that the
same file can be used for either tree.
*******************************************************************************/
bool get_words(char * file_name, vector<string> &w, char type) {
	int i, j;
	int len = 0;
	ifstream in;
	in.open(file_name);
	if (!in.is_open()) {
		cout << "The genome file could not be opened. Check the location.\t";
		return false;
	}

	char * word = new char[11]; //this is a default, we'll be looking at words of size 10
	while (in.peek() != EOF) {
		in >> word[0];
		len++;
	}             //gets the length of the sequence
	in.clear();
	in.close();
	in.open(file_name); //have to close and reopen file to reset filestream to beginning of file

	for (i = 0; i < 10; i++) {

		in >> word[i];
		
		if (word[i] < 97)
			word[i] += 32;     //makes it lowercase
		if (type == 'B' || type == 'b') //if doing BTree, translates 4 letter code into two letter code
		{
			if (word[i] == 'a' || word[i] == 'g'){
				word[i] = 'r';
			} //purine
			else{
				word[i] = 'y';
			}  //pyrimidine
		}

	}
	word[10] = '\0';
	w.push_back(word);
	for (i = 1; i < (len - 10 - 1); i++)   //read until the end of the file
	{
		//shift
		for (j = 0; j < 9; j++)
			word[j] = word[j + 1];
		in >> word[9];
		if (word[9] < 97)
			word[9] += 32;     //makes it lowercase
		if (type == 'B' || type == 'b') {
			if (word[9] == 'a' || word[9] == 'g')
				word[9] = 'r';  //purine
			else
				word[9] = 'y';   //pyrimidine
		}
		word[10] = '\0';
		//cout << i << "\t" << word << endl;
		//cout.flush();
		w.push_back(word);
	}
	in.clear();
	in.close();
	return true;
}

/*******************************************************************************
This function takes the reads file name to read and reads each individual word
in the file and stores each word in a vector.
The vector is passed to this function as a parameter -- by reference such
that the calling function has access to the vector of words.
Type='B' means you are doing a binary tree. Type='Q' means you are doing
the quartenary tree. This function will translate the file such that the
same file can be used for either tree.
*******************************************************************************/
bool get_reads(char * file_name, vector<string> &r, char type) {
	int i;
	ifstream in;
	in.open(file_name);
	if (!in.is_open()) {
		cout << "The read file could not be opened. Check the location.\t";
		return false;
	}

	char * word = new char[20]; //this is a default, we'll be looking at words of size 10

	while (in.peek() != EOF) {
		in.getline(word, 20, '\n');
		for (i = 0; i < 10; i++) {
			if (word[i] < 97)
				word[i] += 32;
		}     //makes it lowercase
		/*if (type == 'B' || type == 'b') //if doing QTree, translates 4 letter code into two letter code
		{
		for (i = 0; i < 10; i++) {
		if (word[i] == 'a' || word[i] == 'g')
		word[i] = 'r';  //purine
		else
		word[i] = 'y';   //pyrimidine
		}
		}*/
		r.push_back(word);
	}
	in.clear();
	in.close();
	delete word;
	return true;
}

bool write_vector_to_screen(vector<string> v) {
	int i;
	for (i = 0; i < v.size(); i++)
		cout << v[i] << endl;

	return true;
}

bool write_vector_to_file(vector<string> v, char * file_name) {
	ofstream out;
	out.open(file_name);
	int i;
	for (i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	out.clear();
	out.close();
	return true;
}



