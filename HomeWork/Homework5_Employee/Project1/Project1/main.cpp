//  main.cpp
//  Homework2
//Zac Gallagher
//

#include <iostream>
#include "Employee.h"
#include <cstring>
#include <string>
#include <fstream> 
#include <cstring>
using namespace std;

int main(int argc, const char * argv[]) {
	Employee **  people;

	string filename;
	int num_of_employess=0;
	string input;
	ifstream in;
	cout << "Enter a file name: " << endl;
	cin >> filename;
	in.open(filename);
	
	
	in >> num_of_employess; 
	
	
	
	in.ignore(1, '\n');

	
	people = new Employee*[num_of_employess];
	int i = 0; 
	
	while (in.peek() != EOF){
		
				Employee  * noob= new Employee();
				
				//microsoft doesnt like strcpy so i had to use strcpy_s 
				char *words;
				getline(in, input, ',');
				words = new char [strlen(input.c_str())+1];
				strcpy_s(words, 30, input.c_str());
				noob->set_name(words);

				
				getline(in, input, ',');
				words = new char[strlen(input.c_str()) + 1];
				strcpy_s(words, 30, input.c_str());
				noob->set_position(words);


				int numbers; 
				getline(in, input, ',');//date of birth
				words = new char[strlen(input.c_str()) + 1];
				numbers = atoi(words); 
				noob->set_dob(numbers);

				getline(in, input, ','); //salary
				words = new char[strlen(input.c_str()) + 1];
				numbers = atoi(words);
				noob->set_salary(numbers);


				getline(in, input, ',');
				words = new char [strlen(input.c_str())+1];
				strcpy_s(words, 30, input.c_str());
				noob->set_status(words[1]);


				getline(in, input, ','); //eid
				words = new char[strlen(input.c_str()) + 1];
				numbers = atoi(words);
				noob->set_eid(numbers);
				
		
				i++;


				}
	in.clear();
	in.close();
	for (i = 0;  i < num_of_employess; i++){
		
		people[i]->write_console(); 
		
	}
	
	//Please review Examples/Week_3/fstream_examples.cpp as well as video on file input and output
	//Ask user to input filename which is employees.txt
	//open the file read the first line and assign it to num_of_employees;
	//Create an array of employees with the size that you just got
	//ignore the the next line which is the header
	//iterate through the file
	//Create a dynamic employee object and assign it to an index example people[i]=new Employee();
	//while iterating like the example that is in fstream_examples, use the , to delimit and grab each input with the input variable and call the setter for the employee object
	//delete Employee object to release memory and start over again
	//close the file
	// now create a for loop and call write_console for each employee in people array
	//delete array
return 0;}
