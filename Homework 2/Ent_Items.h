
//Alex Kesler
//CSCE 1040
//Homework 3


#ifndef ENT_ITEMS_H
#define ENT_ITEMS_H
#include "Ent_Item.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Ent_Items{
	protected:
		vector<Ent_Item> items;
	public:
		void Add(Ent_Item i);
		void Edit(Ent_Item i);
		void Delete(int id);
		std::vector<Ent_Item>::iterator Search(int id);
		void PrintAllOf();
		void PrintDetails(Ent_Item c);
		ostream& compile(ostream& os);
		friend ostream& operator<<(ostream& os, Ent_Items& ents);
		friend istream& operator>>(istream& is, Ent_Items& ents);
	};
#endif