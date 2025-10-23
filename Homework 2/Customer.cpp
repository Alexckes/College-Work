
//Alex Kesler
//CSCE 1040
//Homework 2

using namespace std;

#include "Customer.h"
#include <string>

Customer::Customer(){
	ID = 0;
	ccNum = 0;
	name = "none";
	ccExpDate = 0;
	ccValKey = 0;
	numOfMovies = 0;
}
Customer::Customer(int i, int c, string nm, int e, int k, int n){
	ID = i;
	ccNum = c;
	name = nm;
	ccExpDate = e;
	ccValKey = k;
	numOfMovies = n;

}
void Customer::SetID(int id){
ID = id;
}
int Customer::GetID(){
return ID;
}
void Customer::SetccNum(int n){
ccNum = n;
}
int Customer::GetccNum(){
return ccNum;
}
void Customer::SetName(string n){
name = n;
}
string Customer::GetName(){
return name;
}
void Customer::SetccExpDate(int d){
ccExpDate = d;
}
int Customer::GetccExpDate(){
return ccExpDate;
}
void Customer::SetccValKey(int k){
ccValKey = k;
}
int Customer::GetccValKey(){
return ccValKey;
}
void Customer::SetNumOfMovies(int n){
numOfMovies = n;
}
int Customer::GetNumOfMovies(){
return numOfMovies;
}
/*bool Customer::operator==(Customer c){
	if(GetID() != c.GetID()) return false;
	if(GetccNum() != c.GetccNum()) return false;
	if(GetName() != c.GetName()) return false;
	if(GetccExpDate() != c.GetccExpDate()) return false;
	if(GetccValKey() != c.GetccValKey()) return false;
	if(GetNumOfMovies() != c.GetNumOfMovies()) return false;
}*/