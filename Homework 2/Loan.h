
//Alex Kesler
//CSCE 1040
//Homework 2


#ifndef LOAN_H
#define LOAN_H
#include <string>
using namespace std;
class Loan{
	private:
		int loanID;
		int ent_ItemID;
		int custID;
		int dueDate;
		int dueTime;
		string status;
	public:
		Loan();
		Loan(int l, int e, int c, int d, int t, string s);
		void SetLoanID(int id);
		int GetLoanID();
		void SetEnt_ItemID(int id);
		int GetEnt_ItemID();
		void SetStatus(string s);
		string GetStatus();
		void SetDueDate(int d);
		int GetDueDate();
		void SetCustID(int id);
		int GetCustID();
		void SetDueTime(int t);
		int GetDueTime();
};

#endif