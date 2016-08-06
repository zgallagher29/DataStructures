//
//  Pack.h
//  sandbox
//
//  Created by keetz on 7/20/16.
//  Copyright © 2016 Kathryn Eaton. All rights reserved.
//

#ifndef BPack_h
#define BPack_h
#include <cstring>
#include <string>
#include <stack>
#include <vector>
#include "Traveler.h"

using namespace std;

class BPack{

private:
	string type;        //weekender
	double curweight;  //current weight of the bag
	double curvolume;
	double curprice;
	double maxWeight; //the max weight a bag can handle KG
	double maxVol;    //max volume bag can in LITERS
	double maxPrice;    //max price that Traveler will pay=budget



public:
	int nights;
	string file_name;
	
	struct Item {
		string name;
		double weight;
		double volume;
		double dom_price;
		double abr_price;
		double price_using;
		Item(){ name = "No Name"; volume = 0.0; dom_price = 0.0; abr_price = 0.0; price_using = 0.0; };
	}; typedef struct Item Item;
	std::vector <Item> items;
	
	BPack();    //default constructor
	BPack(string t, double mw, double mv, double mp); //actual constructor
	~BPack();   //destructor
	BPack backpack();
	void        set_type(string t); //setters
	void        set_mw(double mw);
	void        set_mv(double mv);
	void        set_mp(double mp);
	void        set_w(double w);
	void        set_v(double v);
	void        set_p(double p);
	string      get_type();  //getters
	double      get_mw();
	double      get_mv();
	double      get_mp();
	double      get_w();
	double      get_v();
	double      get_p();
	string      read_file(Traveler *t);
	double      find_price(Item new_item);
	void        find_pack_type(BPack &backpack);
	void        add_item(struct Item *bp, stack<Item> *sBP, int iN);
	bool        under_max( int n, BPack *b, Traveler &t);
	//void        swap_items(stack<Item> &bp, vector <Item> &i, int iN, int tO);
	void        remove_item(stack<Item>*bp, vector<Item> &it, int itemNum);
	int        is_in(vector <Item> &bp, string find_this);
	void        create(Traveler *t);
	void		write_file(stack<Item>&bp,Traveler &t);

};

#endif
/* BPack_h */