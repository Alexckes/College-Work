
//Alex Kesler
//CSCE 1040
//Homework 2


using namespace std;

#include "Movie.h"
#include <string>
Movie::Movie(){
	title = "na";
	releaseDate = 0;
	rating = "na";
	duration = 0;
	rentCost = 0;
	replaceCost = 0;
}
/*Movie(string tt, int rd, string r, int dr, int rc, int rpl):Ent_Item(int i, int c, string s, int l){
	title = tt;
	releaseDate = rd;
	rating = r;
	duration = dr;
	rentCost = rc;
	replaceCost = rpl;
}*/

void Movie::SetTitle(string t){
title = t;
}
string Movie::GetTitle(){
return title;
}
void Movie::SetReleaseDate(int d){
releaseDate = d;
}
int Movie::GetReleaseDate(){
return releaseDate;
}
void Movie::SetRating(string r){
rating = r;
}
string Movie::GetRating(){
return rating;
}
void Movie::SetDuration(int d){
duration = d;
}
int Movie::GetDuration(){
return duration;
}
void Movie::SetRentCost(int rc){
rentCost = rc;
}
int Movie::GetRentCost(){
return rentCost;
}
void Movie::SetReplaceCost(int c){
replaceCost = c;
}
int Movie::GetReplaceCost(){
return replaceCost;
}
string Movie::type(){
return "movie";
}
void Movie::Print(){
	cout << "ID: " << getId() << endl;
	cout << "Cost: " << getCost() << endl;
	cout << "Status: " << getStatus() << endl;
	cout << "Loan Period: " << getLoanPeriod() << endl;
	cout << "Title: " << GetTitle() << endl;
	cout << "Rating: " << GetRating() << endl;
	cout << "Release Date: " << GetReleaseDate() << endl;
	cout << "Duration: " << GetDuration() << endl;
	cout << "Cost to Rent: " << GetRentCost() << endl;
	cout << "Cost to Replace: " << GetReplaceCost() << endl;
}

string Movie::compile(){
	return to_string(getId()) + '/' + to_string(getCost()) + '/' + getStatus() + '/' + to_string(getLoanPeriod()) + '/' + 
GetTitle() + '/' + GetRating() + '/' + to_string(GetReleaseDate()) + '/' + to_string(GetDuration()) + '/' + to_string(GetRentCost())
+ '/' + to_string(GetReplaceCost());
}
