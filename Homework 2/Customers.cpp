
//Alex Kesler
//CSCE 1040
//Homework 2 & 3

#include <iostream>
#include <string>
#include <vector>
#include "Customers.h"
using namespace std;

void Customers::Add(Customer c){
	allCustomers.push_back(c);
}
void Customers::Edit(Customer c){
	string prompt;
	cout << "What do you wish to edit?" << endl;
	getline(cin,prompt);
	//std::vector<Customer>::iterator it1 = allCustomers.begin();
	//it1 = Search(c);
	if(prompt == "ID"){
		cout << "What is the new id?" << endl;
		int i;
		cin >> i;
		cin.ignore();
		Search(c.GetID())->SetID(i);
	}
	else if(prompt == "Credit Card Number"){
		cout << "What is the new credit card number?" << endl;
		int i;
		cin >> i;
		cin.ignore();
		Search(c.GetID())->SetccNum(i);
	}
	else if(prompt == "Name"){
		cout << "What is the new name?" << endl;
		string n;
		getline(cin,n);
		Search(c.GetID())->SetName(n);
	}
	else if(prompt == "Credit Card Expiration Date"){
		cout << "What is the new credit card expiration date? (yyyymmdd)" << endl;
		int i;
		cin >> i;
		cin.ignore();
		Search(c.GetID())->SetccExpDate(i);
	}
	else if(prompt == "Credit Card Validation Key"){
		cout << "What is the new credit card validation key?" << endl;
		int i;
		cin >> i;
		cin.ignore();
		Search(c.GetID())->SetccValKey(i);
	}
	else if(prompt == "Number Of Movies Active"){
		cout << "What is the new number of movies active?" << endl;
		int i;
		cin >> i;
		cin.ignore();
		Search(c.GetID())->SetNumOfMovies(i);
	}
	
}
void Customers::Delete(int id){
	vector<Customer>::iterator itr;
	int i = 0;
	for(itr = allCustomers.begin(); itr != allCustomers.end(); ++itr){
	if((*itr).GetID() == id){
	allCustomers.erase(allCustomers.begin() +i);
}
i += 1;
}
}
std::vector<Customer>::iterator Customers::Search(int id){
	vector<Customer>::iterator itr;
	for(itr = allCustomers.begin(); itr != allCustomers.end(); ++itr){
		if((*itr).GetID() == id){
			return itr;
		}
}
vector<Customer> temp;
Customer c;
c.SetID(-1);
temp.push_back(c);
itr = temp.begin();
return itr;
}
void Customers::PrintAllOf(){
	vector<Customer>::iterator itr;
	for(itr = allCustomers.begin(); itr != allCustomers.end(); ++itr){
	cout << "Customer " << (*itr).GetID() << endl;
	}
}
void Customers::PrintDetails(Customer c){
	cout << "Customer's Name: " << c.GetName() << endl;
	cout << "ID: " << c.GetID() << endl;
	cout << "Credit Card Number: " << c.GetccNum() << endl;
	cout << "Credit Card Expiration Date: " << c.GetccExpDate() << endl;
	cout << "Credit Card Validation Key: " << c.GetccValKey() << endl;
	cout << "Number of Movies active: " << c.GetNumOfMovies() << endl << endl;

}
ostream& Customers::compile(ostream& os){
	std::vector<Customer>::iterator itr;
	for(itr = allCustomers.begin(); itr != allCustomers.end(); ++itr){
		string temp = to_string((*itr).GetID()) + '/' + to_string((*itr).GetccNum()) + '/' +
(*itr).GetName() + '/' + to_string((*itr).GetccExpDate()) + '/' + 
to_string((*itr).GetccValKey()) + '/' + to_string((*itr).GetNumOfMovies());
	os << temp << endl;
	}
return os;
}