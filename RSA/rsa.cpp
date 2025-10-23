#ifndef RSA_FLAG
#define RSA_FLAG
#include <iostream>
#include <iterator>
#include <utility>
#include <cmath>
using namespace std;
#define ULONG unsigned long int
class rsa{

	private:

		pair<int,int> pvtkey;
		int primeP;
		int primeQ;
		int secretM;
		int calculateE(int b){
			int e = 2;
			while( gcd(e, b - 1) != 1 )
				e++;
			return e;
		}

		int calculateD(int e, int m){
			int d = 2;
			while(((d*e)%m) != 1)
				d++;
			return d;
		}

		ULONG gcd(ULONG x, ULONG y)
		// Calculates the greatest common divisor of x and y
		{
			if(!x)
			return y;
			return gcd(y%x, x);
		}

		ULONG gcdExtended(ULONG a, ULONG b, ULONG* x, ULONG* y)
		{
    			// Base Case
    			if (a == 0)
    			{
        			*x = 0, *y = 1;
       				 return b;
    			}
   			 // To store results of recursive call
   			 ULONG x1, y1;
   			 ULONG gcd = gcdExtended(b % a, a, &x1, &y1);
  			  // Update x and y using results of recursive
   			 // call
   			 *x = y1 - (b / a) * x1;
  			  *y = x1;
  			  return gcd;
		}

		ULONG modularCongruence(ULONG a, ULONG m)
		{
    			ULONG x, y;
    			//ULONG g =
			gcdExtended(a, m, &x, &y);
			return (x % m + m) % m;
		}

		ULONG computeRsa(ULONG a, ULONG b, ULONG c)
		// Calculates (a^b)%c
		{
			ULONG y, z, i, j, k;
    			y=a; z=(ULONG)1;
			j=ceil(log(b+1)/log(2))*8;
			for(i=1,k=1; k<=j; k++,i=i<<1)
  		  	{
				if(b&i)
				{
       		 			 z = z * y % c;
				}
				y = y * y % c;
			}
			return z;
		}

		ULONG encrypt(char p){
			ULONG a, b, c;
			a = (int)p;
			b = pubkey.first;
			c = pubkey.second;
			return computeRsa(a, b, c);
		}

		char decrypt(ULONG a){
			ULONG b, c, p;
			b = pvtkey.first;
			c = pvtkey.second;
			p = computeRsa(a, b, c);
			return char((int)p);
		}

	public:
	
		pair<int,int> pubkey;

		rsa(){
			pubkey = make_pair(0,0);
			pvtkey = make_pair(0,0);
		}

		void create(int p, int q){
			primeP = p;
			primeQ = q;
			int n = p * q;
			int m = (p-1)*(q-1);
			secretM = m;
			int b;
			if(q > p)
				b = q;
			else
				b = p;
			int e = calculateE(b);
			int d = calculateD(e,m);
			pubkey = make_pair(e,n);
			pvtkey = make_pair(d,n);
		}

		void CryptChar(char c){
			cout << "\nPlain Text = " << (int)c;
			ULONG crypt = encrypt(c);
			cout << "\ncrypto = " << crypt;
			char de = decrypt(crypt);
			cout << "\ndecrypted output = " << (int)de << " " << de << "\n";
		}

		void print(){
			
			cout<<"p = " << primeP << "and Q = " << primeQ << " is SECRET!\n\n\n";
			cout<<"n = "<<pubkey.second<<"\n";
			cout<<"m = "<<secretM<<"\n";
			cout<<"e = "<<pubkey.first<<"\n";
			cout<<"d = "<<pvtkey.first<<"\n\n";
			cout<<"public key:	"<<pubkey.first<<"	"<<pubkey.second<<"\n";
			cout<<"private key:	"<<pvtkey.first<<"	"<<pvtkey.second<<"\n";
		}
};
#endif