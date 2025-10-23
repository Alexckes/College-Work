#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Customer.h"
#include "Customers.h"
#include "Loan.h"
#include "Loans.h"
#include "Ent_Item.h"
#include "Ent_Items.h"
#include "Movie.h"
#include "Game.h"
#include <cstring>
using namespace std;
ostream& operator<<(ostream& os, Ent_Items& ents){
	return ents.compile(os);
}
ostream& operator<<(ostream& os, Customers& custs){
	return custs.compile(os);

}
ostream& operator<<(ostream& os, Loans& ls){
	return ls.compile(os);
}
Ent_Items ERead(fstream& file){
	string str;
	Ent_Items e;
	while(getline(file,str)){
		int p = 0;
		string temp;
		vector<string> info;
		while((p = str.find("/")) != string::npos){
			temp = str.substr(0, p);
			info.push_back(temp);
			str.erase(0,p+1);
		}
		if(info.size() == 10){
			Movie m;
			m.setId(stoi(info.at(0)));
			m.setCost(stoi(info.at(1)));
			m.setStatus(info.at(2));
			m.setLoanPeriod(stoi(info.at(3)));
			m.SetTitle(info.at(4));
			m.SetRating(info.at(5));
			m.SetReleaseDate(stoi(info.at(6)));
			m.SetDuration(stoi(info.at(7)));
			m.SetRentCost(stoi(info.at(8)));
			m.SetReplaceCost(stoi(info.at(9)));
			e.Add(m);
		}
		if(info.size() == 11){
			Game g;
			g.setId(stoi(info.at(0)));
			g.setCost(stoi(info.at(1)));
			g.setStatus(info.at(2));
			g.setLoanPeriod(stoi(info.at(3)));
			g.SetRating(info.at(4));
			g.SetGenre(info.at(5));
			g.SetTitle(info.at(6));
			g.SetReleaseDate(stoi(info.at(7)));
			g.SetStudioCompName(info.at(8));
			g.SetRentCost(stoi(info.at(9)));
			g.SetReplaceCost(stoi(info.at(10)));
			e.Add(g);
		}
	}
	return e;
}
Customers CRead(fstream& file){
	string str;
	Customers e;
	while(getline(file,str)){
		int p = 0;
		string temp;
		vector<string> info;
		while((p = str.find("/")) != string::npos){
			temp = str.substr(0, p);
			info.push_back(temp);
			str.erase(0,p+1);
		}
			Customer g;
			g.SetID(stoi(info.at(0)));
			g.SetccNum(stoi(info.at(1)));
			g.SetName(info.at(2));
			g.SetccExpDate(stoi(info.at(3)));
			g.SetccValKey(stoi(info.at(7)));
			g.SetNumOfMovies(stoi(info.at(8)));
			e.Add(g);
		
	}
	return e;
}
Loans LRead(fstream& file){
	string str;
	Loans e;
	while(getline(file,str)){
		int p = 0;
		string temp;
		vector<string> info;
		while((p = str.find("/")) != string::npos){
			temp = str.substr(0, p);
			info.push_back(temp);
			str.erase(0,p+1);
		}
			Loan g;
			g.SetLoanID(stoi(info.at(0)));
			g.SetEnt_ItemID(stoi(info.at(1)));
			g.SetStatus(info.at(2));
			g.SetDueDate(stoi(info.at(3)));
			g.SetCustID(stoi(info.at(7)));
			g.SetDueTime(stoi(info.at(8)));
			e.Add(g);
		
	}
	return e;
}


int main() {
	fstream Customerfile;
	Customerfile.open ("CustomerStorage.txt", ios::out | ios::in);
	fstream Loanfile;
	Loanfile.open ("LoanStorage.txt", ios::out | ios::in);
	fstream Itemfile;
	Itemfile.open ("ItemStorage.txt", ios::out | ios::in);
	bool active = true;
	while(active){
	char menu;
	cout << "MENU" << endl;
	cout << "c - customer submenu" << endl;
	cout << "m - movie submenu" << endl;
	cout << "g - game submenu" << endl;
	cout << "l - loan submenu" << endl;
	cout << "q - quit greenbox" << endl;
	cout << "Choose an option:" << endl;
	cin >> menu;
	cin.ignore();
	if(menu == 'c'){
		bool c_active = true;
		while(c_active){
		char c_menu;
		cout << "CUSTOMER MENU" << endl;
		cout << "a - add customer" << endl;
		cout << "e - edit a customer" << endl;
		cout << "d - delete a customer" << endl;
		cout << "f - find a customer" << endl;
		cout << "s - list every customer" << endl;
		cout << "i - list details for a customer" << endl;
		cout << "q - quit to main menu" << endl;
		cout << "Choose an option:" << endl;
		cin >> c_menu;
		cin.ignore();
		if(c_menu == 'a'){
			Customers cs = CRead(Customerfile);
			cout << "What is the customer's id?" << endl;
			int id;
			cin >> id;
			cin.ignore();
			cout << "What is the customer's credit card number?" << endl;
			int ccnum;
			cin >> ccnum;
			cin.ignore();
			cout << "What is the customer's name?" << endl;
			string name;
			getline(cin,name);
			cout << "What is the customer's credit card's expiration date? (yyyymmdd)" << endl;
			int ccexpdate;
			cin >> ccexpdate;
			cin.ignore();
			cout << "What is the customer's credit card's validation key?" << endl;
			int key;
			cin >> key;
			cin.ignore();
			cout << "How many entertainment items does the customer currently have rented out?" << endl;
			int num;
			cin >> num;
			cin.ignore();
			cs.Add(*(new Customer(id,ccnum,name,ccexpdate,key,num)));
			Customerfile.close();
			Customerfile.open("CustomerStorage.txt", std::ofstream::out | std::ofstream::trunc);
			Customerfile.close();
			Customerfile.open ("CustomerStorage.txt", ios::out | ios::in);
			Customerfile << cs;
		}
		if(c_menu == 'e'){
			Customers cs = CRead(Customerfile);
			cout << "What is the customer's id?" << endl;
			int id;
			cin >> id;
			cin.ignore();
			cs.Edit(*(cs.Search(id)));
			Customerfile.close();
			Customerfile.open("CustomerStorage.txt", std::ofstream::out | std::ofstream::trunc);
			Customerfile.close();
			Customerfile.open ("CustomerStorage.txt", ios::out | ios::in);
			Customerfile << cs;
		}
		if(c_menu == 'd'){
			Customers cs = CRead(Customerfile);
			cout << "What is the customer's id?" << endl;
			int id;
			cin >> id;
			cin.ignore();
			cs.Delete(id);
			Customerfile.close();
			Customerfile.open("CustomerStorage.txt", std::ofstream::out | std::ofstream::trunc);
			Customerfile.close();
			Customerfile.open ("CustomerStorage.txt", ios::out | ios::in);
			Customerfile << cs;
		}
		if(c_menu == 'f'){
			Customers cs = CRead(Customerfile);
			cout << "What is the customer's id?" << endl;
			int id;
			cin >> id;
			cin.ignore();
			std::vector<Customer>::iterator itr = cs.Search(id);
			if((*itr).GetID()!=-1){
				cout << "Customer " << (*itr).GetName() << " found." << endl;
			}
			else{
				cout << "Customer not found" << endl;
			}
		}
		if(c_menu == 's'){
			Customers cs = CRead(Customerfile);
			cs.PrintAllOf();
		}
		if(c_menu == 'i'){
			Customers cs = CRead(Customerfile);
			cout << "What is the customer's id?" << endl;
			int id;
			cin >> id;
			cin.ignore();
			cs.PrintDetails(*(cs.Search(id)));
		}
		if(c_menu == 'q'){
			c_active = false;
		}
		}
	}
	if(menu == 'm'){
		bool m_active = true;
		while(m_active){
		char m_menu;
		cout << "MOVIE MENU" << endl;
		cout << "a - add movie" << endl;
		cout << "e - edit a movie" << endl;
		cout << "d - delete a movie" << endl;
		cout << "f - find a customer" << endl;
		cout << "s - list every customer" << endl;
		cout << "i - list details for a customer" << endl;
		cout << "q - quit to main menu" << endl;
		cout << "Choose an option:" << endl;
		cin >> m_menu;
		cin.ignore();
		if(m_menu == 'a'){
			Ent_Items es = ERead(Itemfile);
			cout << "What is the movie's id?" << endl;
			int id;
			cin >> id;
			cin.ignore();
			cout << "What is the movie's cost?" << endl;
			int cost;
			cin >> cost;
			cin.ignore();
			cout << "What is the movie's status?" << endl;
			string s;
			getline(cin,s);
			cout << "What is the movie's loan period?" << endl;
			int lp;
			cin >> lp;
			cin.ignore();
			cout << "What is the movie's title?" << endl;
			string tt;
			getline(cin,tt);
			cout << "What is the movie's release date?" << endl;
			int rd;
			cin >> rd;
			cin.ignore();
			cout << "What is the movie's rating?" << endl;
			string r;
			getline(cin,r);
			cout << "What is the movie's duration?" << endl;
			int dr;
			cin >> dr;
			cin.ignore();
			cout << "What is the movie's cost to rent?($1.00 = 100)" << endl;
			int rc;
			cin >> rc;
			cin.ignore();
			cout << "What is the movie's cost to replace?" << endl;
			int rpl;
			cin >> rpl;
			cin.ignore();
			Movie m;
			m.setId(id);
			m.setCost(cost);
			m.setStatus(s);
			m.setLoanPeriod(lp);
			m.SetTitle(tt);
			m.SetReleaseDate(rd);
			m.SetRating(r);
			m.SetDuration(dr);
			m.SetRentCost(rc);
			m.SetReplaceCost(rpl);
			es.Add(m);
			Itemfile.close();
			Itemfile.open("ItemStorage.txt", std::ofstream::out | std::ofstream::trunc);
			Itemfile.close();
			Itemfile.open ("ItemStorage.txt", ios::out | ios::in);
			Itemfile << es;
		}
		if(m_menu == 'e'){
			Ent_Items es = ERead(Itemfile);
			cout << "What is the movie's id?" << endl;
			int id;
			cin >> id;
			cin.ignore();
			es.Edit(*(es.Search(id)));
			Itemfile.close();
			Itemfile.open("ItemStorage.txt", std::ofstream::out | std::ofstream::trunc);
			Itemfile.close();
			Itemfile.open ("ItemStorage.txt", ios::out | ios::in);

			Itemfile << es;

		}
		if(m_menu == 'd'){
			Ent_Items es = ERead(Itemfile);
			cout << "What is the movie's id?" << endl;
			int id;
			cin >> id;
			cin.ignore();
			es.Delete(id);
			Itemfile.close();
			Itemfile.open("ItemStorage.txt", std::ofstream::out | std::ofstream::trunc);
			Itemfile.close();
			Itemfile.open ("ItemStorage.txt", ios::out | ios::in);

Itemfile << es;

		}
		if(m_menu == 'f'){
			Ent_Items es = ERead(Itemfile);
			cout << "What is the movie's id?" << endl;
			int id;
			cin >> id;
			cin.ignore();
			std::vector<Ent_Item>::iterator itr = es.Search(id);
			if((*itr).getId()!=-1){
				cout << "Movie found!" << endl;
			}
			else
				cout << "Movie not found." << endl;
		}
		if(m_menu == 's'){
			Ent_Items es = ERead(Itemfile);
			es.PrintAllOf();
		}
		if(m_menu == 'i'){
			Ent_Items es = ERead(Itemfile);
			cout << "What is the movie's id?" << endl;
			int id;
			cin >> id;
			cin.ignore();
			es.PrintDetails(*(es.Search(id)));
		}
		if(m_menu == 'q'){
			m_active = false;
		}
		}
	}
	if(menu == 'g'){
		bool g_active = true;
		while(g_active){
		char g_menu;
		cout << "GAME MENU" << endl;
		cout << "a - add game" << endl;
		cout << "e - edit a game" << endl;
		cout << "d - delete a game" << endl;
		cout << "f - find a game" << endl;
		cout << "s - list every game" << endl;
		cout << "i - list details for a game" << endl;
		cout << "q - quit to main menu" << endl;
		cout << "Choose an option:" << endl;
		cin >> g_menu;
		cin.ignore();
		if(g_menu == 'a'){
			Ent_Items es = ERead(Itemfile);
			cout << "What is the game's id?" << endl;
			int id;
			cin >> id;
			cin.ignore();
			cout << "What is the game's cost?" << endl;
			int cost;
			cin >> cost;
			cin.ignore();
			cout << "What is the game's status?" << endl;
			string s;
			getline(cin,s);
			cout << "What is the game's loan period?" << endl;
			int lp;
			cin >> lp;
			cin.ignore();
			cout << "What is the game's rating?" << endl;
			string r;
			getline(cin,r);
			cout << "What is the game's genre?" << endl;
			string g;
			getline(cin,g);
			cout << "What is the game's title?" << endl;
			string tt;
			getline(cin,tt);
			cout << "What is the game's release date? (yyyymmdd)" << endl;
			int rd;
			cin >> rd;
			cin.ignore();
			cout << "What is the game's studio and company name?" << endl;
			string scn;
			getline(cin,scn);
			cout << "What is the game's cost to rent?($1.00 = 100)" << endl;
			int rc;
			cin >> rc;
			cin.ignore();
			cout << "What is the game's cost to replace?" << endl;
			int rpl;
			cin >> rpl;
			cin.ignore();
			Game G;
			G.setId(id);
			G.setCost(cost);
			G.setStatus(s);
			G.setLoanPeriod(lp);
			G.SetTitle(tt);
			G.SetReleaseDate(rd);
			G.SetRating(r);
			G.SetGenre(g);
			G.SetRentCost(rc);
			G.SetReplaceCost(rpl);
			G.SetStudioCompName(scn);
			es.Add(G);
			Itemfile.close();
			Itemfile.open("ItemStorage.txt", std::ofstream::out | std::ofstream::trunc);
Itemfile.close();
			Itemfile.open ("ItemStorage.txt", ios::out | ios::in);

			
Itemfile << es;

		}
		if(g_menu == 'e'){
			Ent_Items es = ERead(Itemfile);
			cout << "What is the game's id?" << endl;
			int id;
			cin >> id;
			cin.ignore();
			es.Edit(*(es.Search(id)));
			Itemfile.close();
			Itemfile.open("ItemStorage.txt", std::ofstream::out | std::ofstream::trunc);
Itemfile.close();
			Itemfile.open ("ItemStorage.txt", ios::out | ios::in);

			
Itemfile << es;

		}
		if(g_menu == 'd'){
			Ent_Items es = ERead(Itemfile);
			cout << "What is the game's id?" << endl;
			int id;
			cin >> id;
			cin.ignore();
			es.Delete(id);
			Itemfile.close();
			Itemfile.open("ItemStorage.txt", std::ofstream::out | std::ofstream::trunc);
Itemfile.close();
			Itemfile.open ("ItemStorage.txt", ios::out | ios::in);

			
Itemfile << es;

		}
		if(g_menu == 'f'){
			Ent_Items es = ERead(Itemfile);
			cout << "What is the game's id?" << endl;
			int id;
			cin >> id;
			cin.ignore();
			std::vector<Ent_Item>::iterator itr = es.Search(id);
			if((*itr).getId()!=-1){
				cout << "Game found!" << endl;
			}
			else
				cout << "Game not found." << endl;

		}
		if(g_menu == 's'){
			Ent_Items es = ERead(Itemfile);
			es.PrintAllOf();
		}
		if(g_menu == 'i'){
			Ent_Items es = ERead(Itemfile);
			cout << "What is the game's id?" << endl;
			int id;
			cin >> id;
			cin.ignore();
			es.PrintDetails(*(es.Search(id)));
		}
		if(g_menu == 'q'){
			g_active = false;
		}
		}
	}
	if(menu == 'l'){
		bool l_active = true;
		while(l_active){
		char l_menu;
		cout << "LOAN MENU" << endl;
		cout << "a - add loan" << endl;
		cout << "e - edit a loan" << endl;
		cout << "d - delete a loan" << endl;
		cout << "f - find a loan" << endl;
		cout << "i - list details for a loan" << endl;
		cout << "m - lists all loans for one movie or game" << endl;
		cout << "c - lists all loans of one customer" << endl;
		cout << "l - lists all loans ever" << endl;
		cout << "q - go back to main menu" << endl;
		cout << "Choose an option:" << endl;
		cin >> l_menu;
		cin.ignore();
		if(l_menu == 'a'){
			Loans ls = LRead(Loanfile);
			Ent_Items es = ERead(Itemfile);
			Customers cs = CRead(Customerfile);
			cout << "What is the loan's id?" << endl;
			int lid;
			cin >> lid;
			cin.ignore();
			cout << "What is the loan's entertainmet item's id?" << endl;
			int eid;
			cin >> eid;
			cin.ignore();
			cout << "What is the loan's customer's id?" << endl;
			int cid;
			cin >> cid;
			cin.ignore();
			cout << "What is the loan's due date?" << endl;
			int dd;
			cin >> dd;
			cin.ignore();
			cout << "What is the loan's due time?" << endl;
			int dt;
			cin >> dt;
			cin.ignore();
			cout << "What is the loan's status?" << endl;
			string s;
			getline(cin,s);
			cout <<"What day is it? (yyyymmdd)" << endl;
			int day;
			cin >> day;
			cin.ignore();
			cout << "What time is it? (hhmmss)" << endl;
			int tim;
			cin >> tim;
			cin.ignore();
			vector<int> eiids = ls.CSearch(cid);
			bool gotted = false;
			for(int x = 0; x < eiids.size(); x++){
				if((*es.Search(eiids.at(x))).getStatus() == "Overdue" || (*es.Search(eiids.at(x))).getStatus() == "Lost"){
					gotted = true;
				}
			}
			if((*es.Search(eid)).getStatus() != "In"){
				cout << "Sorry, that item is currenly unavailable" << endl;
			}
			else if((*cs.Search(cid)).GetccExpDate() <= day){
				cout <<"Sorry, but your credit card is expired" << endl;
			}
			else if(gotted){
				cout << "Sorry, but you currently have an itme either lost or overdue" << endl;
			}
			else if(eiids.size() > 2){
				cout << "Sorry, but you currently have too many movies checked out." << endl;
			}
			else{
				Loan l;
				l.SetLoanID(lid);
				l.SetCustID(cid);
				l.SetEnt_ItemID(eid);
				l.SetStatus(s);
				l.SetDueDate(dd);
				l.SetDueTime(dt);
				ls.Add(l);
			}
			Loanfile.close();
			Loanfile.open("LoanStorage.txt", std::ofstream::out | std::ofstream::trunc);
			Loanfile.close();

			Loanfile.open ("LoanStorage.txt", ios::out | ios::in);
			Loanfile << ls;
		}
		if(l_menu == 'e'){
			Loans ls = LRead(Loanfile);
			cout << "What is the loan's id?" << endl;
			int id;
			cin >> id;
			cin.ignore();
			ls.Edit(*(ls.LSearch(id)));
			Loanfile.close();
			Loanfile.open("LoanStorage.txt", std::ofstream::out | std::ofstream::trunc);
			Loanfile.close();
			Loanfile.open ("LoanStorage.txt", ios::out | ios::in);
			Loanfile << ls;

		}
		if(l_menu == 'd'){
			Loans ls = LRead(Loanfile);
			cout << "What is the loan's id?" << endl;
			int id;
			cin >> id;
			cin.ignore();
			ls.Delete(id);
			Loanfile.close();
			Loanfile.open("LoanStorage.txt", std::ofstream::out | std::ofstream::trunc);
Loanfile.close();
			Loanfile.open ("LoanStorage.txt", ios::out | ios::in);
			
Loanfile << ls;
		}
		if(l_menu == 'f'){
			Loans ls = LRead(Loanfile);
			cout << "What is the loan's id?" << endl;
			int id;
			cin >> id;
			cin.ignore();
			std::vector<Loan>::iterator itr = ls.LSearch(id);
			if((*itr).GetLoanID()!=-1){
				cout << "Loan found!" << endl;
			}
			else
				cout << "Loan not found." << endl;

		}
		if(l_menu == 'i'){
			Loans ls = LRead(Loanfile);
			cout << "What is the loan's id?" << endl;
			int id;
			cin >> id;
			cin.ignore();
			ls.PrintDetails(*(ls.LSearch(id)));
		}
		if(l_menu == 'm'){
			Ent_Items es = ERead(Itemfile);
			Loans ls = LRead(Loanfile);
			cout << "What is the item's id?" << endl;
			int id;
			cin >> id;
			cin.ignore();
			ls.PrintLoansOfEnt_Item(id);
		}
		if(l_menu == 'c'){
			Customers cs = CRead(Customerfile);
			Loans ls = LRead(Loanfile);
			cout << "What is the customer's id?" << endl;
			int id;
			cin >> id;
			cin.ignore();
			ls.PrintLoansOfCustomer(id);
		}
		if(l_menu == 'l'){
			Loans ls = LRead(Loanfile);
			ls.PrintAllLoans();
		}
		if(l_menu == 'q'){
			l_active = false;
		}
		}
	}
	if(menu == 'q'){
		active = false;
	}
	}
Customerfile.close();
Loanfile.close();
Itemfile.close();
return 0;
}