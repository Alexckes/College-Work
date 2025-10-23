
//Alex Kesler
//CSCE 1040
//Homework 2


using namespace std;

#include "Loan.h"
#include <string>

Loan::Loan(){
	loanID = 0;
	ent_ItemID = 0;
	custID = 0;
	dueDate = 0;
	dueTime = 0;
	status = "none";
}
Loan::Loan(int l, int e, int c, int d, int t, string s){
	loanID = l;
	ent_ItemID = e;
	custID = c;
	dueDate = d;
	dueTime = t;
	status = s;
}

void Loan::SetLoanID(int id){
loanID = id;
}
int Loan::GetLoanID(){
return loanID;
}
void Loan::SetEnt_ItemID(int id){
ent_ItemID = id;
}
int Loan::GetEnt_ItemID(){
return ent_ItemID;
}
void Loan::SetStatus(string s){
status = s;
}
string Loan::GetStatus(){
return status;
}
void Loan::SetDueDate(int d){
dueDate = d;
}
int Loan::GetDueDate(){
return dueDate;
}
void Loan::SetCustID(int id){
custID = id;
}
int Loan::GetCustID(){
return custID;
}
void Loan::SetDueTime(int t){
dueTime = t;
}
int Loan::GetDueTime(){
return dueTime;
}