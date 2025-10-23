
//Alex Kesler
//CSCE 1040
//Homework 2


#ifndef GAME_H
#define GAME_H
#include "Ent_Item.h"
#include <string>
using namespace std;
class Game: public Ent_Item{
	private:
		string rating;
		string genre;
		string title;
		int releaseDate;
		string studioCompName;
		int rentCost;
		int replaceCost;
	public:
		Game();
		//Game(string r, string g, string t, int rd, string scn, int rc, int rpl):Ent_Item(int i, int c, string s, int l);
		void SetRating(string r);
		string GetRating();
		void SetGenre(string g);
		string GetGenre();
		void SetTitle(string t);
		string GetTitle();
		void SetReleaseDate(int rt);
		int GetReleaseDate();
		void SetStudioCompName(string scn);
		string GetStudioCompName();
		void SetRentCost(int rc);
		int GetRentCost();
		void SetReplaceCost(int c);
		int GetReplaceCost();
		string type();
		void Print();
		string compile();
};

#endif