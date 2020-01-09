#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <string>
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
cout<<"\r\n"<<"Menu:\r\n"<<"1: Afficher la catalogue\r\n"<<"2: Rechercher\r\n"<<"3: Ajouter un trajet simple\r\n"<<"4: Ajouter un trajet compose\r\n"<<"5: Rechercher en mode avancee\r\n"<<"6: Chargement sans selection\r\n"<<"7: Sauvegarde\r\n"<<"8: Quitter\r\n";
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
	char choice;
	cout<<"\r\n"<<"Menu:\r\n"<<"1: Chargement sans selection\r\n"<<"2: Chargement selon le type des trajets\r\n"<<"3: Chargement selon la ville de depart et/ou la ville d'arrivee\r\n"<<"4: Chargement selon une selection de trajets\r\n";
	cin >> choice;
	if(choice == '1'){
	string nomficher;
	cout << "Saisisez le nom de ficher :" << endl;
	cin >> nomficher;
	fstream entree(nomficher.c_str(),fstream::in | fstream::out);
	entree.seekp(0,ios::beg);
	c ->Charger(entree);
	}
	if(choice == '2'){
	string nomficher;
	cout << "Saisisez le nom de ficher :" << endl;
	cin >> nomficher;
	cout << "Saisisez le type des trajets ( 0 pour un trajet simple, 1 pour un trajet compose ) :" << endl;
	string TypeSelece;
	cin >> TypeSelece;
	fstream entree(nomficher.c_str(),fstream::in | fstream::out);
	entree.seekp(0,ios::beg);
	c ->Charger(entree,TypeSelece);
	}
	if(choice == '3'){
	string nomficher;
	cout << "Saisisez le nom de ficher :" << endl;
	cin >> nomficher;
	cout << "Saisisez la ville de depart :" << endl;
	cout << "Si vous ne voulez pas choisir selon la ville de depart, saisisez TBD" << endl;
	char * Dept = new char [20];
	cin >> Dept;
	cout << "Saisisez la ville d'arrivee :" << endl;
	cout << "Si vous ne voulez pas choisir selon la ville d'arrivee, saisisez TBD" << endl;
	char * Arri = new char [20];
	cin >> Arri;
	fstream entree(nomficher.c_str(),fstream::in | fstream::out);
	entree.seekp(0,ios::beg);
	c ->Charger(entree,Dept,Arri);
	delete [] Dept;
	delete [] Arri;
	}
	if(choice == '4'){
	string nomficher;
	cout << "Saisisez le nom de ficher :" << endl;
	cin >> nomficher;
	cout << "Saisisez l'indice de la premiere ligne :" << endl;
	int LigneTete;
	cin >> LigneTete;
	cout << "Saisisez l'indice de la derniere ligne :" << endl;
	int LigneFin;
	cin >> LigneFin;
	fstream entree(nomficher.c_str(),fstream::in | fstream::out);
	entree.seekp(0,ios::beg);
	c ->Charger(entree,LigneTete,LigneFin);
	}
	}
	if(choix == '7') {
		char choice;
		cout<<"\r\n"<<"Menu:\r\n"<<"1: Sauvegarder sans selection\r\n"<<"2: Sauvegarder selon le type des trajets\r\n"<<"3: Sauvegarder selon la ville de depart et/ou la ville d'arrivee\r\n"<<"4: Sauvegarder selon une selection de trajets\r\n";
		cin >> choice;
		if(choice == '1'){
			string nomficher;
			cout << "Saisisez le nom de ficher :" << endl;
			cin >> nomficher;
			fstream sortie(nomficher.c_str(),fstream::out);
			sortie.seekp(0,ios::beg);
			c->Sauvegarder(sortie);
		}
		if(choice == '2') {
			string nomficher;
			cout << "Saisisez le nom de ficher :" << endl;
			cin >> nomficher;
			cout << "Saisisez le type des trajets ( 0 pour un trajet simple, 1 pour un trajet compose ) :" << endl;
			string TypeSelece;
			cin >> TypeSelece;
			fstream sortie(nomficher.c_str(),fstream::out);
			sortie.seekp(0,ios::beg);
			c ->Sauvegarder(sortie,atoi(TypeSelece.c_str())); // apparently can't use stoi() introduced in c++11
		}
	}
	if(choix == '8')
	{
	Fin = 1;
	}	
}
delete c;
cout << "au revoir\r\n";
return 0;
}
