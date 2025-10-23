#include <iostream>
#include "rsa.cpp"

using namespace std;

int main(){
	cout<<"user will give us two primes under or equal two 73\n";
	int p;
	int q;
	cin>>p;
	cin>>q;
	rsa R;
	R.create(p,q);
	R.print();
	cout<<"\nEnter a character: ";
	char a;
	cin>>a;
	R.CryptChar(a);
	cout<<"\nEnter a character: ";
	cin>>a;
	R.CryptChar(a);
	cout<<"\nEnter a character: ";
	cin>>a;
	R.CryptChar(a);
}