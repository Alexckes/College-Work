#include <iostream>
//#include "itemType.h"
using namespace std;

template <class elementType>
class listType
{

	private:
		static const int HASH_SPACE = 0x10; // 16 in hex

		// the definition of the struct nodeType is private
		struct nodeType
		{
			elementType payLoad;
			nodeType* next;

			nodeType()
			{
				next=NULL;

				return;
			}
		};

		nodeType **roots, **envPtr;


		int getHashIndex(unsigned long k)
		{
			return k%HASH_SPACE;
		}


	public:
		listType()
		{
			roots = new nodeType*[HASH_SPACE];

			for(int i=0; i<HASH_SPACE; i++)
				roots[i]=NULL;

			envPtr=NULL;
		}

		void create(){
			roots = new nodeType*[HASH_SPACE];

			for(int i=0; i<HASH_SPACE; i++)
				roots[i]=NULL;

			envPtr=NULL;
		}

		void put(elementType &e){
			if(!isThere(e)){
				*envPtr=new nodeType;
				(*envPtr)->payLoad=e;
			}
			return;
		}

		void remove(elementType &e){
			if(isThere(e)){
				if((*envPtr)->next){
					(*envPtr)->payLoad = ((*envPtr)->next)->payLoad;
					(*envPtr)->next = ((*envPtr)->next)->next;
				}
				else{
					*envPtr = NULL;
				}
			}
			return;
		}

		bool isThere(elementType &e)  // demonstrating getHashIndex
		{
			unsigned long h = e.getHash();

			int i = getHashIndex(h);

			envPtr = &roots[i];
			while(*envPtr && (*envPtr)->payLoad != e)
				envPtr=&(*envPtr)->next;

			return *envPtr;
		}

		void print(string s){
			cout<<"\n\n**** "<<s<<" ****\n\n";
			for(int x =0; x < HASH_SPACE; x++){
				cout<<"\tBucket: "<<x<<"\n";
				nodeType *p;
				p = roots[x];
				while(p){
					cout<<"\t\t"<<p->payLoad<<"\n";
					p=p->next;
				}
				cout<<"\n";
			}
			cout<<"\n*********************\n";
		}
};


