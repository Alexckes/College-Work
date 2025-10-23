
//Alex Kesler
//CSCE 1040
//Homework 2

#include <string>
#include <iostream>
using namespace std;

#include "Game.h"
Game::Game(){
	rating = "na";
	genre = "na";
	title = "na";
	releaseDate = 0;
	studioCompName = "na";
	rentCost = 0;
	replaceCost = 0;
}
/*Game(string r, string g, string t, int rd, string scn, int rc, int rpl):Ent_Item(int i, int c, string s, int l){
	rating = r;
	genre = g;
	title = t;
	releaseDate = rd;
	studioCompName = scn;
	rentCost = rc;
	replaceCost = rpl;

}*/

void Game::SetRating(string r){
rating = r;
}
string Game::GetRating(){
return rating;
}
void Game::SetGenre(string g){
genre = g;
}
string Game::GetGenre(){
return genre;
}
void Game::SetTitle(string t){
title = t;
}
string Game::GetTitle(){
return title;
}
void Game::SetReleaseDate(int rt){
releaseDate = rt;
}
int Game::GetReleaseDate(){
return releaseDate;
}
void Game::SetStudioCompName(string scn){
studioCompName = scn;
}
string Game::GetStudioCompName(){
return studioCompName;
}
void Game::SetRentCost(int rc){
rentCost = rc;
}
int Game::GetRentCost(){
return rentCost;
}
void Game::SetReplaceCost(int c){
replaceCost = c;
}
int Game::GetReplaceCost(){
return replaceCost;
}
string Game::type(){
return "game";
}
void Game::Print(){
	cout << "ID: " << getId() << endl;
	cout << "Cost: " << getCost() << endl;
	cout << "Status: " << getStatus() << endl;
	cout << "Loan Period: " << getLoanPeriod() << endl;
	cout << "Rating: " << GetRating() << endl;
	cout << "Genre: " << GetGenre() << endl;
	cout << "Title: " << GetTitle() << endl;
	cout << "Release Date: " << GetReleaseDate() << endl;
	cout << "Studio and Company Name: " << GetStudioCompName() << endl;
	cout << "Cost to Rent" << GetRentCost() << endl;
	cout << "Cost to Replace" << GetReplaceCost() << endl;
}

string Game::compile(){
	return to_string(getId()) + '/' + to_string(getCost()) + '/' + getStatus() + '/' + to_string(getLoanPeriod()) + '/' +
GetRating() + '/' + GetGenre() + '/' + GetTitle() + '/' + to_string(GetReleaseDate()) + '/' + GetStudioCompName() + '/' +
to_string(GetRentCost()) + '/' + to_string(GetReplaceCost());
}