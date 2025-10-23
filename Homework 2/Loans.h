
//Alex Kesler
//CSCE 1040
//Homework 3


#ifndef LOANS_H
#define LOANS_H
#include <string>
#include <vector>
#include "Loan.h"
using namespace std;
class Loans{
	protected:
		vector<Loan> allLoans;
	public:
		void Add(Loan i);
		void Edit(Loan i);
		void Delete(int id);
		std::vector<Loan>::iterator LSearch(int id);
		vector<int> CSearch(int id);
		int MSearch(int id);
		void PrintDetails(Loan c);
		void PrintLoansOfEnt_Item(int entid);
		void PrintLoansOfCustomer(int custid);
		void PrintAllLoans();
		ostream& compile(ostream& os);
		friend ostream& operator<<(ostream& os, Loans& ls);
		friend istream& operator>>(istream& is, Loans& ls);
};
#endif