
//Alex Kesler
//CSCE 1040
//Homework 3


using namespace std;
#include <string>
#include <iostream>

#include "Ent_Item.h"

Ent_Item::Ent_Item(){
	id = 0;
	cost = 0;
	status = "none";
	loanPeriod = 0;
}
Ent_Item::Ent_Item(int i, int c, string s, int l){
	id = i;
	cost = c;
	status = s;
	loanPeriod = l;
}


int Ent_Item::getId(){
	return id;
}

void Ent_Item::setId(int i){
	id = i;
}
int Ent_Item::getCost(){
	return cost;
}

void Ent_Item::setCost(int c){
	cost = c;
}
string Ent_Item::getStatus(){
	return status;
}

void Ent_Item::setStatus(string s){
	status = s;
}
int Ent_Item::getLoanPeriod(){
	return loanPeriod;
}

void Ent_Item::setLoanPeriod(int lp){
	loanPeriod = lp;
}

string Ent_Item::type(){
	return "none specified";
}

void Ent_Item::Print(){
	cout << "ID: " << getId() << endl;
	cout << "Cost: " << getCost() << endl;
	cout << "Status: " << getStatus() << endl;
	cout << "Loan Period: " << getLoanPeriod() << endl;
}

string Ent_Item::compile(){
	return to_string(getId()) + '/' + to_string(getCost()) + '/' + getStatus() + '/' + to_string(getLoanPeriod());
}