/*************************************************************************
Catalogue  -  description
-------------------
debut                : 20/11
copyright            : (C) 2019 par Muye HE, Tuoyuan TAN
e-mail               : $EMAIL$
*************************************************************************/
//---------- R¨¦alisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst¨¨me
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M¨¦thodes publiques

Catalogue::Catalogue(){
	// constructeur par defaut qui ne fait rien et qui n'a pas de parametres
}//----- Fin de M¨¦thode


void Catalogue::Afficher(){
	//Algorithme :
	if(Nbtraj==0){
		cout<<"aucun trajet enregistre "<<endl;
	}
	else{
		int i;
		for(i=0;i<Nbtraj;i++){
		Trajets[i]->Afficher();
		}
	}		 
}//----- Fin de M¨¦thode

void Catalogue::Chercher(char * Dep,char * Arr){
	//Algorithme :
	int trouve=0;	
	if(Nbtraj==0){
		cout<<"il n'y a aucun trajet dans la bibliotheque"<<endl;
	}else{
		int i;
		for(i=0;i<Nbtraj;i++){
			if(strcmp(Trajets[i]->Depart,Dep) == 0 && strcmp(Trajets[i]->Arrivee,Arr) == 0){
			Trajets[i]->Afficher();
			trouve = 1;
			}
		}
	}
	//Quand il n'y a pas de solutions :
	if(trouve==0){
		cout<<"aucun trajet correspondant a votre besoin "<<endl;
	}	
}//----- Fin de M¨¦thode

void Catalogue::ChercherAvancee(char * Dep, char * Arr){
	//Initialisation :
	if(Nbtraj != 0){
	int nbr = 0;
	int * found = new int ();
	* found = 0;
	int * tab = new int [Nbtraj];
	//Chercher de maniere recursive :
	ChercherCorres(Dep,Arr,tab,nbr,found);
	//Quand il n'y a pas de solutions :
	if(* found == 0){
	cout<<"aucun trajet correspondant a votre besoin "<<endl;
	}
	delete [] tab;
	delete found;
	} else {
	cout<<"aucun trajet correspondant a votre besoin "<<endl;
	}
}//----- Fin de M¨¦thode


void Catalogue::AjouterC(TrajetCompose* t){
	//Algorithme :
	if(Nbtraj == Max){
	int i;
	//prolongement quand le nombre des Trajets depasse le maximum
	Max = Max + 5;
	Trajet** T = new Trajet* [Max];
	for(i=0;i<Nbtraj;i++){
	T[i] = Trajets[i];
	}
	delete [] Trajets;
	T[Nbtraj] = t;
	Nbtraj++;
	Trajets = T;
	}else{
	Trajets[Nbtraj] = t;
	Nbtraj++;
	}
}//----- Fin de M¨¦thode	

void Catalogue::AjouterS(TrajetSimple* t){
	//Algorithme :
	if(Nbtraj == Max){
	int i;
	//prolongement quand le nombre des Trajets depasse le maximum
	Max = Max + 5;
	Trajet** T = new Trajet* [Max];
	for(i=0;i<Nbtraj;i++){
	T[i] = Trajets[i];
	}
	delete [] Trajets;
	T[Nbtraj] = t;
	Nbtraj++;
	Trajets = T;
	}else{
	Trajets[Nbtraj] = t;
	Nbtraj++;
	}
}//----- Fin de M¨¦thode	

Catalogue::~Catalogue(){
	// Fonctionnement g¨¦n¨¦ral :
	//Destructeur qui detruit tous les Trajets stockes dans ce Catalogue un par un
	int i;
	for(i=0;i<Nbtraj;i++){
	delete Trajets[i];
	}
	delete [] Trajets;
}//----- Fin de M¨¦thode


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protected

//------------------------------------------------------- Methodes privees
void Catalogue::ChercherCorres(char* Dep, char* Arr, int* tab, int nbr, int* found) {
	//Algorithme :
	nbr++;
	int i;
	int j;
	for (i = 0; i < Nbtraj; i++) {
		if (strcmp(Trajets[i]->Depart, Dep) == 0) {
			if (strcmp(Trajets[i]->Arrivee, Arr) == 0) {
				*found = 1;
				tab[nbr - 1] = i;
				for (j = 0; j < nbr; j++) {
					Trajets[tab[j]]->Afficher();
				}
				cout << endl;
				continue;
			}
			else {
				int existence = 0;
				if (nbr >= 2) {
					if (strcmp(Trajets[tab[0]]->Depart, Trajets[i]->Arrivee) == 0) {  //Pour eviter de faire des boucles
						existence = 1;
					}
				}
				for (j = 0; j < nbr - 1; j++) {
					if (strcmp(Trajets[tab[j]]->Arrivee, Trajets[i]->Arrivee) == 0) {  //Pour eviter de faire des boucles
						existence = 1;
					}
				}
				if (existence == 0) {
					tab[nbr - 1] = i;
					ChercherCorres(Trajets[i]->Arrivee, Arr, tab, nbr, found); //Aller plus loin tant que possible
				}
			}
		}
	}
}//----- Fin de M¨¦thode

void Catalogue::Charger(fstream & entree){
	cout << "entrer dans le bloc" << endl;
	while(1){
	cout << "entree.good" << endl;
	char type;
	entree >> type;
	if(type == '2'){
	break;
	}else if(type == '0'){
	cout << "Trajet Simple" << endl;
	char * Dept = new char [20];
	char * Arri = new char [20];
	char * Mode = new char [20];
	entree >> Dept;
	entree >> Arri;
	entree >> Mode;
	TrajetSimple * T0 = new TrajetSimple(Dept,Arri,Mode);
	AjouterS(T0);
	} else if (type == '1'){
	cout << "Trajet Compose" << endl;
	int nbr;
	entree >> nbr;
	int i = 0;
	char * Dept = new char [20];
	entree >> Dept;
	char * DEPT = new char [20];
	strcpy(DEPT,Dept);
	TrajetSimple** LesTrajets = new TrajetSimple* [nbr];
	char * Transfer;
	Transfer = Dept;
	while(i < nbr){
	char * Arri = new char [20];
	entree >> Arri;
	char * T = new char [20];
	strcpy(T,Arri);
	char * Mode = new char [20];
	entree >> Mode;
	TrajetSimple * T0 = new TrajetSimple(Transfer,Arri,Mode);
	LesTrajets [i] = T0;
	Transfer = T;
	i++;
	}
	TrajetCompose * T2 = new TrajetCompose(DEPT, Transfer, LesTrajets, nbr);
	AjouterC(T2);
	}
	}
}




