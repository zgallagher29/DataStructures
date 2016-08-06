//
//  main.cpp
//  7.31
//
//  Created by keetz on 7/31/16.
//  Copyright © 2016 Kathryn Eaton. All rights reserved.
//

#include <stdio.h>
//
//  main.cpp
//  Zac's Backpack Final Proj
//
//  Created by Suzanne Greenwood on 7/20/16.
//  Copyright © 2016 Suzanne Greenwood. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include "Traveler.h"
//#include "BPack.cpp"
#include "BPack.h"

using namespace std;


//getfilecontents is Zac's from the original main file
std::string getFileContents(std::ifstream& File);
int informationBuilder(Traveler *t);
int backPackBuilder(BPack *bp);

int main(int argc, const char * argv[]) {
	string destination;
	string input;
	char * temp;
	ifstream location;

	//this chunk was Zac's from the original main file. I just copy pasted it here
	std::ifstream Header("File1.txt");             //source for how to make art print to screen: http://www.cplusplus.com/forum/general/58945/

	std::string Title = getFileContents(Header);       //Get file

	std::cout << Title << std::endl;               //Print it to the screen
	Header.close();
	//close file

	//system("pause");
	std::ifstream Directions("Directions.txt");          //Open file

	std::string consoleDirections = getFileContents(Directions);       //Get file

	std::cout << consoleDirections << std::endl;               //Print it to the screen

	Directions.close();
	Traveler newTraveler;
	BPack bp;
	if (informationBuilder(&newTraveler) != 0){

		bp.read_file(&newTraveler);
		bp.create(&newTraveler);
		/*   if(backPackBuilder(&bp)){
		cout << "Where are you going on your trip?" << endl;
		cout << "1. Beach /n2. Mountain /n3. Forest /n4. Polar /n0 to Quit" << endl;
		cin >> input;
		read_file(input); */
	}
	cout << "Check you folder for thePlan.txt" << endl;
	system("pause");
	return 0;
	
}

std::string getFileContents(std::ifstream& File)
{
	std::string Lines = "";        //All lines

	if (File)                      //Check if everything is good
	{
		while (File.good())
		{
			std::string TempLine;                  //Temp line
			std::getline(File, TempLine);        //Get temp line
			TempLine += "\n";                      //Add newline character

			Lines += TempLine;                     //Add newline
		}
		return Lines;
	}
	else                           //Return error
	{
		return "ERROR File does not exist.";
	}
}

int informationBuilder(Traveler *t){

	string input = "";
	char*temp;

	cout << "What is your name? Or Enter 0 to Quit " << endl;
	cin >> input;
	if (input == "0"){
		return 0;
	}
	temp = new char[strlen(input.c_str()) + 1];
	strcpy(temp, input.c_str());
	t->setName(temp);
	delete[] temp;

	double money = 0;
	do{
		cout << "What is your budget for the entire trip? Must be at least $200. Do not enter the $ sign. Enter 0 to Quit" << endl;
		cin >> money;
		if (money == 0){
			return 0;
		}
		t->setBudget(money);
	} while (money < 200);

	int number = 0;
	do{

		cout << "How strong are you? On a scale of 1 to 10. 10 being the strongest. Use whole numbers. Enter 0 to Quit" << endl;
		cin >> number;
		if (number == 0){
			return 0;
		}
		t->setStrength(number * 2);

	} while (number< 0 || number>10);


	cout << "Your budget is $" << t->getBudget() << " and your strength is set to " << t->getStrength() << "(strength multiplied by 2)." << endl;


	return 1;
}