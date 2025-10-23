
//Alex Kesler
//CSCE 1040
//Homework 2
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
using namespace std;
class Customer{
	private:
		int ID;
		int ccNum;
		string name;
		int ccExpDate;
		int ccValKey;
		int  numOfMovies;
	public:
		Customer();
		Customer(int i, int c, string nm, int e, int k, int n);
		void SetID(int id);
		int GetID();
		void SetccNum(int n);
		int GetccNum();
		void SetName(string n);
		string GetName();
		void SetccExpDate(int d);
		int GetccExpDate();
		void SetccValKey(int k);
		int GetccValKey();
		void SetNumOfMovies(int n);
		int GetNumOfMovies();
		//bool operator==(Customer c);
};

#endif