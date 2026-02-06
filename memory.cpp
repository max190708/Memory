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
	for(int i=0;i<x;i++) // ciclo per stampare il tabellone
	{
		cout<<endl<<" * ";
		for(int r=1;r<y;r++)
		{
			cout<<" * ";
		}
	}
	cout<<endl;
	const int b=x*y/2;
	char a [b]={};
	for (int i=0;i<b;i++) //generazione lettere 
    {
        bool valido;
        do {
            valido=true;
            a[i]=rand()%26+65;
            for (int t=0;t<i;t++)
            {
                if (a[i]==a[t])
                {
                    valido=false;
                    break;
                }
            }
        } while (!valido);

        cout <<"Il "<<i+1<<" valore è: "<<a[i]<< endl;
    }
    const int h=b*2;
    char g [h]={};
    int count=0;
    	for(int t=0;t<h;t++)	
    	{
    	g[t]=a[count];
    	g[t+1]=a[count];
    	count++;
		}
		for(int t=0;t<h;t++)
		{
		 cout <<"Il "<<t+1<<" valore è: "<<g[t]<< endl;
		}
		
		
		
		
			}
		
	
