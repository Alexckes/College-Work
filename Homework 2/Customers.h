
//Alex Kesler
//CSCE 1040
//Homework 2


#ifndef CUSTOMERS_H
#define CUSTOMERS_H
#include <string>
#include <vector>
using namespace std;
#include "Customer.h"
class Customers{
	protected:
		std::vector<Customer> allCustomers;
	public:
		void Add(Customer c);
		void Edit(Customer c);
		void Delete(int id);
		std::vector<Customer>::iterator Search(int id);
		void PrintAllOf();
		void PrintDetails(Customer c);
		ostream& compile(ostream& os);
		friend ostream& operator<<(ostream& os, Customers& custs);
		friend istream& operator>>(istream& is, Customers& custs);
};
#endif