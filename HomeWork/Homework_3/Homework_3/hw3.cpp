#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

struct word_freq{
	string word; //word itself
	int num_times_occ; //how many times word occured in document
	int num_of_letters; //how many letters in word
};

//this function reads the file and puts it in the vector
bool read_file(char * file_name, vector<string> & w);

//this function finds if the word is already in the array and returns the index
int is_in(string w, vector<word_freq> & wf); 

//this function finds how many times a word occurs
int get_num_occ(string w, vector<word_freq> & wf);

//this function will write a file called 'word_stats.txt'
//and have all the UNIQUE words and how many times they show up
bool write_file(char * file_name, vector<word_freq> & wf);

//this function will check each line and get each word, getting rid of punctuation, newline,tabs, and carriage returns
bool parse_line(char* word, vector<string> &w); 



int main() {

	int i;
	int index;
	string word;
	int num_of_lines = 0;
	int num_of_words=0;
	vector<string> words;
	vector<word_freq> words_occ;
	word_freq new_word;
	string filename;
	string line;
	char * c_filename;
	cout << "Please enter a filename: ";
	getline(cin, filename);
	c_filename = new char[strlen(filename.c_str()) + 1];
	strcpy(c_filename, filename.c_str());
	ifstream lineFile;
	lineFile.open(c_filename);
	while (getline(lineFile, line)){
		++num_of_lines;                 //gets numbers of lines only. does not place into vector or anything

	}

	lineFile.clear();
	lineFile.close();
	read_file(c_filename, words);			//passes in file name and vector. inside the function, it will call parse function 
	
	i = 0;
		for (i = 0; i < words.size(); i++){
			word = words[i];
			is_in(word, words_occ);				//loops through words vector and passes them through with the struct vector
			
		}
		num_of_words = i;

		ofstream writeFile;						//writing to file	
		writeFile.open("occurences.txt");

		for (int n = 0; n < words_occ.size()-1; n++){			//prints on console and in file
			words_occ[n].num_of_letters = (words_occ[n].word.length());
				cout << words_occ[n].word << "    Occurence: " << words_occ[n].num_times_occ << "   Length of word: "<< words_occ[n].num_of_letters<<endl;
				writeFile << words_occ[n].word << "    Occurence: " << words_occ[n].num_times_occ << "   Length of word: " << words_occ[n].num_of_letters << endl;
			}
		cout << "Lines: " << num_of_lines << "|   Total Number of Words: " << num_of_words<<"|  Unique Words: " <<words_occ.size()<< endl; //wasn't sure which want to add so added both total and unique words
		writeFile.clear();
		writeFile.close();
		do{																				//user input data
			cout << "What word do you want to look up or enter 0 to quit?" << endl;
			cin >> word;
			for (int x = 0; x < word.length(); x++){
				word[x] = tolower(word[x]); //makes the user input to lower case to match the vector's words
			}
		
			if ((word != "0")){
				for (int n = 0; n < words_occ.size(); n++){
					if (word == words_occ[n].word){
						cout << words_occ[n].word << "        Occurence: " << words_occ[n].num_times_occ << endl;
						word = "1"; //so it skips the if function below
						break;
					}
				}
				if (word != "1"){
					cout << "Not in vector. Try again." << endl;
					
					cout << " " << endl;
				}
			}
			else{ //when user enters 0
				cout << "Good-Bye!" << endl;
			}
		} while (word != "0");
		

		system("pause");
	
		//if file has been read and all the words are in the "words" vector
	//for loop to go through vector words, check is word with is_in function and it should return an index
	//if index is greater than or equal to 0 the words_occ[index].num_times_occ increased
	//else new word set the word and occurences to 1 and pushback into '"words_occ"

	//Show each word and how many times it occurs, and how many letters in said word example: for loop of 'words_occ'
	//Write the file of all the occurences

	//while loop to ask user "What word do you want to look up or 0 to quit"
	/*do{
		cout << "What word do you want to look up or enter 0 to quit?" << endl;
		if ((word != "0")||(words.)){

		}
		else{
			cout << "Good-Bye!" << endl;
		}
	} while (word != "0");
	//if word is there say word and how many times it occured
	//else word not in vector or 0 to quit*/

	return 0;
}

bool read_file(char * file_name, vector<string> & w){
	ifstream txtFile; //reading file
	txtFile.open(file_name);

	if (txtFile.is_open()){
		cout << "Opening file........" << endl;

	}
	char* charWord;
	string tempWord;
	while (txtFile >> tempWord){ //grabs each word
			
		charWord = new char[strlen(tempWord.c_str())];
		strcpy(charWord, tempWord.c_str());
		
		charWord[0] = tolower(charWord[0]); //source for lowercase : http://www.cplusplus.com/forum/beginner/26964/ 

		parse_line(charWord, w);  
		
	}
	txtFile.clear();
	txtFile.close();
	return true;
}

bool parse_line(char * word, vector<string> &w){
	

		int j = 0;
		for (j=0; j<strlen(word); j++){
		
			if ((ispunct(word[j])||(word[j]==NULL))){ //if the word is punctuation then don't add it
				word[j] = NULL;
				
			}
		
		}
		w.push_back(word);//adds to vecctor
		
		
	
	return true;
}

int is_in(string w, vector<word_freq> & wf){

	
	for (int n = 0; n < wf.size(); n++){
		if (w == wf[n].word){ //only goes through if the word is already in vector
			wf[n].num_times_occ = wf[n].num_times_occ + 1;	//increases occurence
		
			

			return 1;
		}
		
	
	}
	wf.push_back(word_freq());
	int index = 0;						
	if (wf[index].word.empty()){
		wf[index].word = w;
		wf[index].num_times_occ = 1;
		
	}													//for new occurences of a word
	else{
		do{
			index = index + 1;
		}while(!wf[index].word.empty());
		wf[index].word = w;
		wf[index].num_times_occ = 1;

	}
	return 1;
}