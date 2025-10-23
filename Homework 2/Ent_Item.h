
	

//Alex Kesler
//CSCE 1040
//Homework 3


#ifndef ENT_ITEM_H
#define ENT_ITEM_H
#include <string>
using namespace std;
class Ent_Item{
	protected:
		int id;
		int cost;
		string status;
		int loanPeriod;
	public:
		Ent_Item();
		Ent_Item(int i, int c, string s, int l);
		int getId();
		void setId(int i);
		int getCost();
		void setCost(int c);
		string getStatus();
		void setStatus(string s);
		int getLoanPeriod();
		void setLoanPeriod(int lp);
		virtual string type();
		virtual void Print();
		virtual string compile();
		};

#endif