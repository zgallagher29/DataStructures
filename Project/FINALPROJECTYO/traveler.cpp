#include <iostream>
#include "Traveler.h"

using namespace std;

Traveler::Traveler(){
	name = NULL;
	budget = 0;
	strength = 0;



}
char*
Traveler::getName()
{
	//return variable
	return name;
}

//I personally feel we dont need these getters if the setters return the same variables

double
Traveler::getBudget(){
	return budget;
}
int
Traveler::getStrength(){
	return strength;
}

bool
Traveler::setBudget(double money){
	budget = money;
	return budget;
}

bool
Traveler::setName(char* n){
	name = n;
	return name;


}


bool
Traveler::setStrength(int stren){
	strength = stren;
	return stren;
}