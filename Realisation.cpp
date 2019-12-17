#include <stdio.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include "Trajet.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"
#include "Catalogue.h"
using namespace std;
int main(){
Catalogue *c = new Catalogue();
char choix;
int nbr;
int len;
int i;
int Fin = 0;
while(Fin == 0){ 
cout<<"\r\n"<<"Menu:\r\n"<<"1: Afficher la catalogue\r\n"<<"2: Rechercher\r\n"<<"3: Ajouter un trajet simple\r\n"<<"4: Ajouter un trajet compose\r\n"<<"5: Rechercher en mode avancee\r\n"<<"6: Chargement sans selection\r\n"<<"7: Quitter\r\n";
cin >> choix;
	if(choix == '1')
	{
	c->Afficher();
	}
	if(choix == '2')
	{
	char * Dept = new char [20];
	char * Arri = new char [20];
        cout << "Saisissez le lieu de depart: \r\n";
	cin >> Dept;
	len = strlen(Dept);
	char * D = new char [len+1];
	strcpy(D,Dept);
	cout << "Saisissez la destination: \r\n";
	cin >> Arri;
	len = strlen(Arri);
	char * A = new char [len+1];
	strcpy(A,Arri);
	c->Chercher(D,A);
	delete [] D;
	delete [] A;
	delete [] Dept;
	delete [] Arri;
	}
	if(choix == '3')
	{
	char * Dept = new char [20];
	char * Arri = new char [20];
	char * Mode = new char [20];
	cout << "Saisissez le lieu de depart: \r\n";
	cin >> Dept;
	len = strlen(Dept);
	char * D = new char [len+1];
	strcpy(D,Dept);
	cout << "Saisissez la destination: \r\n";
	cin >> Arri;
	len = strlen(Arri);
	char * A = new char [len+1];
	strcpy(A,Arri);
	cout << "Saisissez la mode: \r\n";
	cin >> Mode;
	len = strlen(Mode);
	char * M = new char [len+1];
	strcpy(M,Mode);
	TrajetSimple * T1 = new TrajetSimple(D, A, M);
	c->AjouterS(T1);
	delete [] Dept;
	delete [] Arri;
	delete [] Mode;
	}
	if(choix == '4')
	{
	char * Dept = new char [20];
	cout << "Saisissez le nombre des trajets simples qui constituent ce trajet compose: \r\n";
	cin >> nbr;
	cout << "Saisissez le lieu de depart: \r\n";
	cin >> Dept;
	len = strlen(Dept);
	char * D = new char [len+1];
	strcpy(D,Dept);
	char * DEPT = new char [len+1];
	strcpy(DEPT,Dept);
	TrajetSimple** LesTrajets = new TrajetSimple* [nbr];
	i = 0;
	char * Transfer;
	Transfer = D;
	while(i < nbr){
	char * Arri = new char [20];
	cout << "Saisissez le prochain stop: \r\n";
	cin >> Arri;
	len = strlen(Arri);
	char * A = new char [len+1];
	char * T = new char [len+1];
	strcpy(A,Arri);
	strcpy(T,Arri);
	delete [] Arri;
	char * Mode = new char [20];
	cout << "Saisissez la mode: \r\n";
	cin >> Mode;
	len = strlen(Mode);
	char * M = new char [len+1];
	strcpy(M,Mode);
	delete [] Mode;
	TrajetSimple * T0 = new TrajetSimple(Transfer,A,M);
	LesTrajets [i] = T0;
	Transfer = T;
	i++;
	}
	TrajetCompose * T2 = new TrajetCompose(DEPT, Transfer, LesTrajets, nbr);
	c->AjouterC(T2);
	delete [] Dept;
	}
	if(choix == '5')
	{
	char * Dept = new char [20];
	char * Arri = new char [20];
        cout << "Saisissez le lieu de depart: \r\n";
	cin >> Dept;
	len = strlen(Dept);
	char * D = new char [len+1];
	strcpy(D,Dept);
	cout << "Saisissez la destination: \r\n";
	cin >> Arri;
	len = strlen(Arri);
	char * A = new char [len+1];
	strcpy(A,Arri);
	c->ChercherAvancee(D,A);
	delete [] D;
	delete [] A;
	delete [] Dept;
	delete [] Arri;
	}
	if(choix == '6')
	{
	string nomficher;
	cout << "Saisisez le nom de ficher :" << endl;
	cin >> nomficher;
	fstream entree(nomficher.c_str(),fstream::in | fstream::out);
	entree.seekp(0,ios::beg);
	c ->Charger(entree);
	}
	if(choix == '7')
	{
	Fin = 1;
	}	
}
delete c;
cout << "au revoir\r\n";
return 0;
}
