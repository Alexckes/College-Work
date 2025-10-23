
//Alex Kesler
//CSCE 1040
//Homework 3

#include <iostream>
#include <string>
#include <vector>
#include "Ent_Items.h"
//#include "Movie.h"
//#include "Game.h"
using namespace std;

void Ent_Items::Add(Ent_Item i){
	items.push_back(i);
}

void Ent_Items::Edit(Ent_Item i){
	string prompt;
	cout << "What do you wish to edit?" << endl;
	getline(cin,prompt);
	if(prompt == "ID"){
		cout << "What is the new id?" << endl;
		int id;
		cin >> id;
		cin.ignore();
		Search(i.getId())->setId(id);
	}
	else if(prompt == "Cost"){
		cout << "What is the new cost?" << endl;
		int cost;
		cin >> cost;
		cin.ignore();
		Search(i.getId())->setCost(cost);
	}
	else if(prompt == "Status"){
		cout << "What is the new status?" << endl;
		string status;
		getline(cin,status);
		Search(i.getId())->setStatus(status);
	}
	else if(prompt == "Loan Period"){
		cout << "What is the new loan period?" << endl;
		int lp;
		cin >> lp;
		cin.ignore();
		Search(i.getId())->setLoanPeriod(lp);
	}
	/* else if(prompt == "Title"){
		cout << "What is the new title?" << endl;
		string t;
		getline(cin,t);
		//Search(i.getId())->SetTitle(t);
		if(i.type() == "movie"){
			Search(i.getId())->SetTitle(t);
		}
		else if(i.type() == "game"){
		
		}
	}
	else if(prompt == "Release Date"){
		cout << "What is the new release date? (yyyymmdd)" << endl;
		int rd;
		cin >> rd;
		cin.ignore();
		Search(i.getId())->SetReleaseDate(rd);
	}
	else if(prompt == "Rating"){
		cout << "What is the new rating?" << endl;
		string r;
		getline(cin,r);
		Search(i.getId())->SetRating(r);
	}
	else if(prompt == "Duration"){
		cout << "What is the new duration? (hhmmss)" << endl;
		int d;
		cin >> d;
		cin.ignore();
		Search(i.getId())->SetDuration(d);
	}
	else if(prompt == "Cost to Rent"){
		cout << "What is the new cost to rent?" << endl;
		int rc;
		cin >> rc;
		cin.ignore();
		Search(i.getId())->SetRentCost(rc);
	}
	else if(prompt == "Cost to Replace"){
		cout << "What is the new cost to replace?" << endl;
		int c;
		cin >> c;
		cin.ignore();
		Search(i.getId())->SetReplaceCost();
	}
	else if(prompt == "Genre"){
		cout << "What is the new genre?" << endl;
		string g;
		getline(cin,g);
		Search(i.getId())->SetGenre(g);
	}
	else if(prompt == "Studio and Company Name"){
		cout <<"What is the new studio and company name?" << endl;
		string scn;
		getline(cin,scn);
		Search(i.getId())->SetStudioCompName(scn);
	} */
}
void Ent_Items::Delete(int id){
	vector<Ent_Item>::iterator itr;
	int x = 0;
	for(itr = items.begin(); itr != items.end(); ++itr){
		if((*itr).getId() == id){
		items.erase(items.begin() + x);
		}
		x += 1;
	}
}
std::vector<Ent_Item>::iterator Ent_Items::Search(int id){
	vector<Ent_Item>::iterator itr;
	for(itr = items.begin(); itr != items.end(); ++itr){
		if((*itr).getId() == id){
			return itr;
		}
	}
vector<Ent_Item> temp;
Ent_Item c;
c.setId(-1);
temp.push_back(c);
itr = temp.begin();
return itr;
}
void Ent_Items::PrintAllOf(){
	vector<Ent_Item>::iterator itr;
	for(itr = items.begin(); itr != items.end(); ++itr){
		cout <<  "Entertainment Item " << (*itr).getId() << endl;
	}
}
void Ent_Items::PrintDetails(Ent_Item i){
	i.Print();
}

ostream& Ent_Items::compile(ostream& os){
	std::vector<Ent_Item>::iterator itr;
	for(itr = items.begin(); itr != items.end(); ++itr){
		os << (*itr).compile() << endl;
	}
	return os;
}