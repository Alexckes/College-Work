
//Alex Kesler
//CSE 1040
//Homework 2 & 3

#include <iostream>
#include <string>
#include <vector>
#include "Loans.h"
using namespace std;

void Loans::Add(Loan l){
	allLoans.push_back(l);
}

void Loans::Edit(Loan l){
	string prompt;
	cout << "What do you wish to edit?" << endl;
	getline(cin,prompt);
	if(prompt == "Loan's ID"){
		cout << "What is the new loan id?" << endl;
		int i;
		cin >> i;
		cin.ignore();
		LSearch(l.GetLoanID())->SetLoanID(i);
	}
	else if(prompt == "Entertainment Item's ID"){
		cout << "What is the new entertainment item id?" << endl;
		int i;
		cin >> i;
		cin.ignore();
		LSearch(l.GetLoanID())->SetEnt_ItemID(i);
	}
	else if(prompt == "Customer's ID"){
		cout << "What is the new customer id?" << endl;
		int i;
		cin >> i;
		cin.ignore();
		LSearch(l.GetLoanID())->SetCustID(i);
	}
	else if(prompt == "Due Date"){
		cout << "What is the new due date? (yyyymmdd)" << endl;
		int i;
		cin >> i;
		cin.ignore();
		LSearch(l.GetLoanID())->SetDueDate(i);
	}
	else if(prompt == "Due Time"){
		cout << "What is the new due time? (hhmmss)" << endl;
		int i;
		cin >> i;
		cin.ignore();
		LSearch(l.GetLoanID())->SetDueTime(i);
	}
	else if(prompt == "Status"){
		cout << "What is the new status?" << endl;
		string s;
		getline(cin,s);
		LSearch(l.GetLoanID())->SetStatus(s);
	}
}
void Loans::Delete(int id){
	vector<Loan>::iterator itr;
	int i = 0;
	for(itr = allLoans.begin(); itr != allLoans.end(); ++itr){
		if((*itr).GetLoanID() == id){
			allLoans.erase(allLoans.begin() + i);
		}
		i += 1;
	}
}
std::vector<Loan>::iterator Loans::LSearch(int id){
	vector<Loan>::iterator itr;
	for(itr = allLoans.begin(); itr != allLoans.end(); ++itr){
		if((*itr).GetLoanID() == id){
			return itr;
		}
	}
vector<Loan> temp;
Loan c;
c.SetLoanID(-1);
temp.push_back(c);
itr = temp.begin();
return itr;

}
vector<int> Loans::CSearch(int id){
	vector<Loan>::iterator itr;
	vector<int> i;
	for(itr = allLoans.begin(); itr != allLoans.end(); ++itr){
		if((*itr).GetCustID() == id){
			i.push_back((*itr).GetEnt_ItemID());
		}
	}
return i;

}
int Loans::MSearch(int id){
	vector<Loan>::iterator itr;
	int i = 0;
	for(itr = allLoans.begin(); itr != allLoans.end(); ++itr){
		if((*itr).GetEnt_ItemID() == id){
			i++;
		}
	}
return i;

}


void Loans::PrintDetails(Loan l){
	cout << "Loan's ID: " << l.GetLoanID() << endl;
	cout << "The Loaned Item's ID: " << l.GetEnt_ItemID() << endl;
	cout << "The Customer's ID: " << l.GetCustID() << endl;
	cout << "Loan's Status: " << l.GetStatus() << endl;
	cout << "Loan's Due Date: " << l.GetDueDate() << endl;
	cout << "Loan's Due Time: " << l.GetDueTime() << endl;
}
void Loans::PrintLoansOfEnt_Item(int entid){
	vector<Loan>::iterator itr;
	for(itr = allLoans.begin(); itr != allLoans.end(); ++ itr){
		if((*itr).GetEnt_ItemID() == entid){
			cout << "Loan " << (*itr).GetLoanID() << endl;
			cout << "Item " << entid << endl;
			cout << "Status: " << (*itr).GetStatus() << endl;
		}
	}
}

void Loans::PrintLoansOfCustomer(int custid){
	vector<Loan>::iterator itr;
	for(itr = allLoans.begin(); itr != allLoans.end(); ++ itr){
		if((*itr).GetCustID() == custid){
			cout << "Loan " << (*itr).GetLoanID() << endl;
			cout << "Customer " << custid << endl;
			cout << "Status: " << (*itr).GetStatus() << endl;
		}
	}

}

void Loans::PrintAllLoans(){
	vector<Loan>::iterator itr;
	for(itr = allLoans.begin(); itr != allLoans.end(); ++ itr){
		cout << "Loan " << (*itr).GetLoanID() << endl;
		cout << "Status: " << (*itr).GetStatus() << endl;
	}

}
ostream& Loans::compile(ostream& os){
	std::vector<Loan>::iterator itr;
	for(itr = allLoans.begin(); itr != allLoans.end(); ++itr){
		string temp = to_string((*itr).GetLoanID()) + '/' + to_string((*itr).GetEnt_ItemID())
+ '/' + (*itr).GetStatus() + '/' + to_string((*itr).GetDueDate()) + '/' + to_string((*itr).
GetCustID()) + '/' + to_string((*itr).GetDueTime());
	os << temp << endl;
	}
	return os;

}
