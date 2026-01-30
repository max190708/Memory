#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;
// funzione
	void generazione (int &a, int &b)
	{
	a=rand()%12+4;
	b=rand()%12+4;
	}
int main(int argc, char** argv) {
	srand(time(0));
	int x,y;
	generazione (x,y);
	do
	{
		generazione (x,y);
	}while (x*y%2!=0 || x*y>52);
	int c[x][y]={0}; //la matrice
	for(int i=0;i<x;i++)
	{
		cout<<endl<<" * ";
		for(int r=1;r<y;r++)
		{
			cout<<" * ";
		}
	}
	int b=x*y/2;
	char a [b]={};
	for(int i=0;i<b;i++)
	{
		a[i]=rand()%26+65;
		cout<<"Il "<<i+1<<" valore è: "<<a<<endl;
	}
	
	return 0;
}