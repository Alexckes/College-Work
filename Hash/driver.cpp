#include <iostream>
#include "listType.cpp"
#include "itemType.h"
using namespace std;

int main()
{
	cout<<"Begin\n";

	itemType myItem;
	listType<itemType> myList;
	// HASH_SPACE is 16

	myItem="aaaa";
	myList.put(myItem);
	myItem="bbbb";
	myList.put(myItem);
	myItem="cccc";
	myList.put(myItem);
	myItem="dddd";
	myList.put(myItem);
	myItem="eeee";
	myList.put(myItem);
	myItem="ffff";
	myList.put(myItem);
	myItem="gggg";
	myList.put(myItem);
	myItem="hhhh";
	myList.put(myItem);
	myItem="iiii";
	myList.put(myItem);
	myItem="jjjj";
	myList.put(myItem);
	myItem="kkkk";
	myList.put(myItem);
	myItem="llll";
	myList.put(myItem);
	myItem="mmmm";
	myList.put(myItem);
	myItem="nnnn";
	myList.put(myItem);
	myItem="oooo";
	myList.put(myItem);
	myItem="pppp";
	myList.put(myItem);

	myList.print("part one");

	myItem="gggg";
	myList.remove(myItem);
	myItem="kkkk";
	myList.remove(myItem);
	myItem="hhhh";
	myList.remove(myItem);
	myItem="llll";
	myList.remove(myItem);

	myList.print("part two");

	cout<<"Process Complete\n";
	return 0;
}
