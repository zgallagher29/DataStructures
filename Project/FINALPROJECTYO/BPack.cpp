//
//  BPack.cpp
//  sandbox
//
//  Created by keetz on 7/20/16.
//  Copyright © 2016 Kathryn Eaton. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include "BPack.h"
#include <cstring>
#include <string>
#include "Traveler.h"




using namespace std;


BPack::BPack(){
	type = "No Type Assigned";
	curweight = 0.0; //initialize props of bpack
	curvolume = 0.0;
	curprice = 0.0;
	maxWeight = 0.0;
	maxVol = 0.0;
	maxPrice = 0.0;
	begin(items);
}
BPack::BPack(string t, double mw, double mv, double mp){
	set_type(t);
	set_mw(mw);
	set_mv(mv);
	set_mp(mp);
	begin(items);
}

/********TODO: MUST MAKE A DESTRUCTOR **************/
BPack :: ~BPack(){
	cout << "Backpack Obliterated!!" << endl;
}



void BPack::set_type(string pType){    //setters
	type = pType;
}
void BPack::set_mw(double mw){
	maxWeight = mw;
}
void BPack::set_mv(double mv){
	maxVol = mv;
}
void BPack::set_mp(double mp){
	maxPrice = mp;
}
void BPack::set_w(double w){
	curweight = w;
}
void BPack::set_v(double v){
	curvolume = v;
}
void BPack::set_p(double p){
	curprice = p;
}

string BPack::get_type(){  //getters
	return type;
}
double BPack::get_mw(){
	return maxWeight;
}
double BPack::get_mv(){
	return maxVol;
}
double BPack::get_mp(){
	return maxPrice;
}
double BPack::get_w(){
	return curweight;
}
double BPack::get_v(){
	return curvolume;
}
double BPack::get_p(){
	return curprice;
}





/*
*
MOVED THIS FROM MAIN.CPP
*
*/
string BPack::read_file(Traveler *t){
	ifstream in;
	string input;
	double budget = 0.0;
	file_name;
	//this chunk is to find where the user is going and open the corresponding file
	cout << "Where are you going on your trip? Enter a number." << endl;
	cout << " 1. Beach \n 2. Mountain \n 3. Forest \n 4. Chicago \n 0. to Quit" << endl;
	cin >> input;
	if (input == "1"){ //add or input == "beach" use tolower also for the other 3.
		file_name = "Beach.txt";
		input = ""; //to clear input for use later
		cout << "Your resort/shelter fee will be $200 a night." << endl;
		budget = 200; 
		
		//the cost of shelter for one night
	}
	else if (input == "2"){
		file_name = "Mountain.txt";
		input = "";
		cout << "Your resort/shelter fee will be $300 a night." << endl;
		budget = 300; //the cost of shelter for one night
	}
	else if (input == "3"){
		file_name = "Forest.txt";
		input = "";
		cout << "Your camp site fee will be $50 a night." << endl;
		budget = 50; //the cost of shelter for one night
	}
	else if (input == "4"){
		file_name = "Chicago.txt";
		input = "";
		cout << "Your hotel fee will be $150 a night." << endl;
		budget = 150; //the cost of shelter for one night
	}
	else if (input == "0"){
		return 0;
	}
	else{
		cout << "User should enter the number of the destination they are visiting." << endl;
		input = "";
	}

	cout << "How many nights are you staying?" << endl;
	cin >> nights;
	budget = budget * nights; //to find the cost of shelter for the whole trip
	
	if (budget > t->getBudget()){//exception in case the budget is too small for the length of trip
		budget = budget / nights;
		cout << "Uh oh. Your budget is too small for this length of a trip." << endl;
		cout << "Enter a smaller number of nights " << endl;
		cin >> nights; 
		budget = budget*nights;
	}
	t->setBudget(t->getBudget() - budget);//creating new budget based on number of nights
	cout << "The cost of shelter for your trip is $" << budget << endl;
	cout << "You have $" << t->getBudget() << " left to spend." << endl;
	cout << " " << endl;
	cout << "Let's start adding items to your bag!" << endl;
	//delete t;
	return file_name;
}

/* Finds which price is lower and assigns the lower to the price_using */
double BPack::find_price(BPack::Item new_item){
	//double p_u;
	if (new_item.dom_price < new_item.abr_price){
		new_item.price_using = new_item.dom_price;
	}
	else {
		new_item.price_using = new_item.abr_price;
	}
	return new_item.price_using;
}

/* Prompts user to enter the number of nights they are staying and assigns them a pack
*
* TOOK THIS FROM MAIN.CPP
*
*/
void BPack::find_pack_type(BPack &backpack){ 
	
	if (1 <= nights  && nights <= 6){
		//set the bag to a certain size
		backpack.set_type("Weekender");
		backpack.set_mv(30);
		backpack.set_mw(25);// liters of volume
	}
	else if (nights >= 7 && nights <= 10){
		//bag size
		backpack.set_type("Multiday");
		backpack.set_mv(50);
		backpack.set_mw(45);
	}
	else{
		//bag size
		backpack.set_type("Extended Trip");
		backpack.set_mv(70);
		backpack.set_mw(45);
	}
	cout << "Your pack type: " << backpack.get_type() << "\nYour max volume: " << backpack.get_mv() << endl;
}

/*
* Checks to see if adding the item will push the pack over its maximums
*/
bool BPack::under_max( int n, BPack *b, Traveler &t){


	if (0 > b->get_w()){
		cout << "Adding new item exceeds maximum weight" << endl;
		return false;
	}
	else if (0> b->get_mv()){
		cout << "Adding new item exceeds maximum volume" << endl;
		return false;
	}
	else if (1 > t.getBudget()){
		cout << "Adding new item exceeds your budget" << endl;
		return false;
	}
	else {
		return true;
	}
}

/* If the item pushes the pack over its max asks 
void BPack::swap_items(stack<Item> &bp, vector <Item> &i, int iN, int tO){
	remove_item(&bp, i, tO);
	add_item(&i[iN], &bp, iN);
	cout << "Item successfully added!" << endl;
	//bp.push(items[iN]);
}*/

/*
* Function to remove items from the Backpack
*/
void BPack::remove_item(stack<Item>*bp, vector<Item> &it, int itemNum){
	int new_w = 0;
	int new_p = 0;
	int new_v = 0;
	vector<Item>tempBag;
	Item tempItem;
	for (int i = 0; i < bp->size(); i++){
		if (bp->top().name == it[itemNum].name){		//REMOVED THE ITEM
			bp->pop();
			new_w = get_w() - bp->top().weight;
			new_p = get_p() - bp->top().price_using;
			new_v = get_v() - bp->top().volume;
			set_w(new_w);
			set_p(new_p);
			set_v(new_v);
			cout << "Item: " << bp->top().name << " successfully removed!" << endl;
		}
		else {				//FAILED TO REMOVE
			cout << "Item not in backpack! Cannot remove!" << endl;
			tempItem = bp->top();
			tempBag.push_back(tempItem);
			bp->pop();
		}
	}
}




/*
* Adds items to the vector and changes the weight, mass and price of the pack
*/
void BPack::add_item(struct Item *bp, stack<Item> *sBP, int iN){
	sBP->push(*bp);//simply just adds the item to the backpack 
	cout << sBP->top().name << " was added into your backpack!" << endl;

	
}

/* Maybe add a funtion that searches the vector and returns a int if the item is in teh vector
could be uesd in create() and remove() and swap() fucntion returns the index of the matching item */


int BPack::is_in(vector <Item> &bp, string find_this){
	int index =0;
	for (int i = 0; i<bp.size(); i++){
		//TODO: make upper/lower immune
		if (find_this == bp[i].name){
			return index = i;
		}
		else {
			return index = -1;
		}
	}
	return index;
}

/*
* Essentailly a main for BPack, lets you add all your items initally until you reach the maximum in any feild
*/
void BPack::write_file(stack<Item>&bp, Traveler &t){
	cout << "Okay! You're all set then! We generated you a file for your trip!" << endl;
	fstream travelFile;
	string travelFileName = "thePlan.txt";
	int size = 0;
	size = bp.size();
	travelFile.open(travelFileName, ios::out);
	travelFile << "Name: " << t.getName() << endl;
	travelFile << "Destination: " << file_name << endl;
	travelFile << "Money to Spend: " << t.getBudget() << endl;
	travelFile << "Items Bought: " << endl;
	for (int y = 0; y < size; y++){    //iterates through the bag and prints to the file. pops after the item has been added
		travelFile << bp.top().name << endl;
		bp.pop();
	}
	travelFile << "Have a great trip!" << endl;
	travelFile.close();


}
void BPack::create(Traveler *t){
	
	stack<Item> stackBP;
	string user_input;
	Item tempItem;
	int tempIndex;
	BPack backpack;
	find_pack_type(backpack);
	ifstream in; //to read destination file
	string input;
	//print options


	in.open(file_name); //read_file will set this as whatever destination file applies

	getline(in, input, '\n');
	int i = 1;
	
int itemNumber = 0;
	while (in.peek() != EOF){   //parses the file location file and stores the items into a vector
		BPack::Item *nItem = new Item;
		
		getline(in, nItem->name, ',');
		cout << i << ". " << nItem->name << endl;
		getline(in, input, ',');
		nItem->weight = stod(input);
		getline(in, input, ',');
		nItem->volume = stod(input);
		getline(in, input, ',');
		nItem->dom_price = stod(input);
		getline(in, input, '\n');
		nItem->abr_price = stod(input);
		nItem->price_using = 0.0;
		items.push_back(*nItem);//added item to the vector
		i++;
		
		cout << "  " << endl;
		delete nItem; //memory allocation!!! =)
		input = ""; 
	}
	
	in.clear();
	in.close();
	cout << "  " << endl;
	cout << "You can carry: " << backpack.get_mw() + t->getStrength() << " pounds (the weight the back pack can carry plus your strength."<< endl;
	backpack.set_w(backpack.get_mw()+t->getStrength());//added the strength of the person to the backpack
	cout << "________________________" << endl;
	string decision = "1";
	while (under_max(itemNumber,&backpack, *t)&&(decision=="1")){//as long as the weight, price, and decision is right then will go through the loop
		int itemNumber = 0;
		do{
			
			cout << "Of the items in the list, which would you like to add? Choose the number. " << endl;
			cin >> itemNumber;

			if (itemNumber<1||itemNumber>items.size()||isdigit(itemNumber)){
				cout << "Enter a valid number." << endl;
				user_input = "NOT VALID";
			}
			else{
				itemNumber = itemNumber - 1;
				cout << "You bought: " << items[itemNumber].name << endl;
				
			}
			

		
		} while (user_input == "NOT VALID");//the user input will be set to not valid and the user will be asked again
		tempItem = items[itemNumber];
		if (under_max( itemNumber, &backpack, *t)){ //tests whether item is cheaper abroad or domestically
		if (items[itemNumber].abr_price > items[itemNumber].dom_price){
			cout << "This item cost more abroad." << endl;
		}
		do{
			cout << "Would you like to buy it abroad or domestically? A or D?" << endl;

			cin >> user_input;


			//TODO: make this upper/ lower immune

			if (user_input == "a" || user_input == "A"){
				t->setBudget(t->getBudget() - items[itemNumber].abr_price);
				backpack.set_w(backpack.get_w() - items[itemNumber].weight);

				add_item(&tempItem, &stackBP, itemNumber);//adds to the user's backpack
				cout << "You have $" << t->getBudget() << " to spend" << endl;
				cout << "You can carry " << backpack.get_w() << " more pounds." << endl;
				user_input = "A";
				//TODO: make upper/ lower immune
			}
			else if (user_input == "d" || user_input == "D"){
				t->setBudget(t->getBudget() - items[itemNumber].dom_price);
				backpack.set_w(backpack.get_w() - items[itemNumber].weight);
				add_item(&tempItem, &stackBP, itemNumber);
				cout << "You have $" << t->getBudget() << " to spend" << endl;
				cout << "You can carry " << backpack.get_w() << " more pounds." << endl;
				user_input = "A";

			}
		} while (user_input!="A");
			cout << "Would you like to keep going?" << endl;
			cout << "You have $" << t->getBudget() << endl;
			cout << "You can fit " << backpack.get_w() <<" pounds." <<endl;
			cout << "Enter 0 to Exit and get your travel file; Enter 1 to continue to add. You cannot add if you're out of your budget." << endl;
			cin >> decision;
		}
	}
	if (decision == "0"){
		cout << "Okay! You're all set then! We generated you a file for your trip!" << endl;
		write_file(stackBP, *t);

	}
	else{
		cout << "Uh oh! \nWould you like  to swap some items out? Enter N to finish, enter R to remove item? Enter 0 to quit. " << endl;
		cin >> user_input;
		toupper(user_input[0]);
		//TODO: make this upper/lower immune
		if (user_input == "S" || user_input == "s"){
			int takeOut = 0;
			cout << "Which item number which you like to take out?" << endl;
			cin >> takeOut;
			takeOut = takeOut - 1;
			t->setBudget(t->getBudget() + items[takeOut].abr_price);
			backpack.set_w(backpack.get_w() + items[takeOut].weight);
			//swap_items(stackBP, items, itemNumber, takeOut);
			t->setBudget(t->getBudget() - items[itemNumber].abr_price);
			backpack.set_w(backpack.get_w() + items[itemNumber].weight);
			write_file(stackBP, *t);


		}
		else if (user_input == "R"){
			int takeOut = 0;
			cout << "Which item number which you like to take out?" << endl;
			cin >> takeOut;
			takeOut = takeOut - 1;
			t->setBudget(t->getBudget() + items[takeOut].abr_price);
			backpack.set_w(backpack.get_w() + items[takeOut].weight);

			remove_item(&stackBP,items, takeOut);
			
		}
		else if (user_input == "N" || user_input == "0"){
			write_file(stackBP, *t);


		}
		else{
			cout << "Okay! You're all set then! We generated you a file for your trip!" << endl;
			write_file(stackBP, *t);
		}
	

	

	}
}