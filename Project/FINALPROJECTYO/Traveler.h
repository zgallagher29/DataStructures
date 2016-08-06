#ifndef Traveler_h
#define Traveler_h
#include <cstring>
#include <iostream>
#include <string>




class           Traveler {
private:
	double             budget; //for the entire trip
	int              strength; // scale of 1-10 maybe?
	char*		name; // first name 

public:
	Traveler();


	int getStrength();
	double getBudget();
	char* getName();
	bool setStrength(int stren);
	bool setName(char* n);
	bool setBudget(double money);

};

#endif Traveler_h