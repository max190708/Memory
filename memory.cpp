#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>
using namespace std;
// funzione
 void generazione (int &a, int &b)
 {
 a=rand()%4+4;
 b=rand()%4+4;
 }
int main(int argc, char** argv) {
 srand(time(0));
 int x,y;
 generazione (x,y);
 do
 {
  generazione (x,y);
 }while (x*y>52);
 char c[x][y]; //la matrice
 bool scoperto[x][y];
 for(int i=0;i<x;i++)
 {
  for(int r=0;r<y;r++)
  {
   scoperto[i][r]=false;
  }
 }
 int tot=x*y;
 int b;
 bool dispari=false;
 if(tot%2!=0) //gestione dispari
 {
  b=(tot-1)/2;
  dispari=true;
 }else
 {
  b=tot/2;
 }
 char a [b];
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
 }
 char temp[tot];
 int count=0;
 for(int t=0;t<b*2;t+=2)
 {
  temp[t]=a[count];
  temp[t+1]=a[count];
  count++;
 }
 if(dispari)
 {
  temp[tot-1]='0';
 }
 for(int i=0;i<tot;i++) //mischio tutto
 {
  int r=rand()%tot;
  char scambia=temp[i];
  temp[i]=temp[r];
  temp[r]=scambia;
 }
 int k=0;
 for(int i=0;i<x;i++) //riempio matrice
 {
  for(int r=0;r<y;r++)
  {
   c[i][r]=temp[k];
   k++;
  }
 }
 int coppie=0;
 int tentativi=0;
 int r1,c1,r2,c2;
 int target=b;
 while(coppie<target){ //ciclo gioco
  cout<<"\033[H\033[2J"; //pulisce schermo
  cout<<"Tentativi: "<<tentativi<<endl;
  cout<<"   ";
  for(int r=0;r<y;r++) cout<<r<<" ";
  cout<<endl;
  for(int i=0;i<x;i++)
  {
   cout<<i<<"  ";
   for(int r=0;r<y;r++)
   {
    if(scoperto[i][r])
    {
     cout<<c[i][r]<<" ";
    }else
    {
     cout<<"* ";
    }
   }
   cout<<endl;
  }
  do
  {
   cout<<"Inserisci riga e colonna 1 carta: ";
   cin>>r1>>c1;
   if(r1<0 || r1>16 || c1<0 || c1>16) // controllo 1
   {
       cout<<"Inserito un valore sbagliato.";
       return 0;
   }
  }while(r1<0 || r1>=x || c1<0 || c1>=y  || scoperto[r1][c1]);
  scoperto[r1][c1]=true;
  cout<<"\033[H\033[2J";
  cout<<"Tentativi: "<<tentativi<<endl;
  cout<<"   ";
  for(int r=0;r<y;r++) cout<<r<<" ";
  cout<<endl;
  for(int i=0;i<x;i++)
  {
   cout<<i<<"  ";
   for(int r=0;r<y;r++)
   {
    if(scoperto[i][r]) cout<<c[i][r]<<" ";
    else cout<<"* ";
   }
   cout<<endl;
  }
  do
  {
   cout<<"Inserisci riga e colonna 2 carta: ";
   cin>>r2>>c2;
   if(r2<0 || r2>16 || c2<0 || c2>16) // controllo 2
   {
       cout<<"Inserito un valore sbagliato.";
       return 0;
   }
  }while(r2<0 || r2>=x || c2<0 || c2>=y || scoperto[r2][c2]);
  scoperto[r2][c2]=true;
  cout<<"\033[H\033[2J";
  cout<<"Tentativi: "<<tentativi<<endl;
  cout<<"   ";
  for(int r=0;r<y;r++) cout<<r<<" ";
  cout<<endl;
  for(int i=0;i<x;i++)
  {
   cout<<i<<"  ";
   for(int r=0;r<y;r++)
   {
    if(scoperto[i][r]) cout<<c[i][r]<<" ";
    else cout<<"* ";
   }
   cout<<endl;
  }
  tentativi++;
  if(c[r1][c1]==c[r2][c2])
  {
   cout<<endl<<"Hai trovato una coppia!"<<endl;
   coppie++;
   sleep(1);
  }
  else
  {
   cout<<endl<<"Non sono uguali..."<<endl;
   sleep(2);
   scoperto[r1][c1]=false; //ricopro
   scoperto[r2][c2]=false;
  }
 }
 cout<<endl<<"COMPLIMENTI! Hai finito in "<<tentativi<<" tentativi."<<endl;
 return 0;
}
