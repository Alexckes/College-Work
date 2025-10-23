
//Alex Kesler
//CSCE 1040
//Homework 2


#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include "Ent_Item.h"
#include <iostream>
using namespace std;
class Movie: public Ent_Item{
	private:
		string title;
		int releaseDate;
		string rating;
		int duration;
		int rentCost;
		int replaceCost;
	public:
		Movie();
		//Movie(string tt, int rd, string r, int dr, int rc, int rpl):Ent_Item(int i, int c, string s, int l);
		void SetTitle(string t);
		string GetTitle();
		void SetReleaseDate(int d);
		int GetReleaseDate();
		void SetRating(string r);
		string GetRating();
		void SetDuration(int d);
		int GetDuration();
		void SetRentCost(int rc);
		int GetRentCost();
		void SetReplaceCost(int c);
		int GetReplaceCost();
		string type();
		void Print();
		string compile();
};

#endif