/*************************************************************************
TrajetCompose  -  description
-------------------
debut                : 20/11
copyright            : (C) 2019 par Muye HE, Tuoyuan TAN
e-mail               : $EMAIL$
*************************************************************************/
//---------- R��alisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst��me
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M��thodes publiques
TrajetCompose::TrajetCompose(char * DEP, char * ARR, TrajetSimple** LesTrajets, const int Nombre):Trajet(DEP, ARR),TrajetsSimples(LesTrajets),NombreTrajets(Nombre){
	//Algorithme :
	//Depart =  DEPART;
	//Arrivee = ARRIVEE;
	//TrajetsSimples = LesTrajets;
	//NombreTrajets = Nombre;
}//----- Fin de M��thode

TrajetCompose::TrajetCompose(){}
	// constructeur par defaut qui ne fait rien et qui n'a pas de parametres
void TrajetCompose::Afficher()
{
	// Mode d'emploi :
	// methode qui affiche dans l'ordre tous les information des TrajetSimples qui constituent ce TrajetCompose
	// 
	int i;
	cout << "de " << TrajetsSimples[0]->Depart << " a " << TrajetsSimples[0]->Arrivee << " en " << TrajetsSimples[0]->Mode;
	for(i=1;i<NombreTrajets;i++)
	{
	cout << " - de " << TrajetsSimples[i]->Depart << " a " << TrajetsSimples[i]->Arrivee << " en " << TrajetsSimples[i]->Mode;
	}
	cout << "\r\n";
}//----- Fin de M��thode

void TrajetCompose::Sauvegarder(fstream & sortie) {
	int i;
	sortie << "1 " << NombreTrajets << " " << TrajetsSimples[0]->Depart << " " << TrajetsSimples[0]->Arrivee << " " << TrajetsSimples[0]->Mode;
	for(i=1;i<NombreTrajets;i++)
	{
	sortie << " " << TrajetsSimples[i]->Arrivee << " " << TrajetsSimples[i]->Mode;
	}
	sortie << "\r\n";
}

TrajetCompose::~TrajetCompose()
{
	// Mode d'emploi :
	//Destructeur qui detruit d'abord les deux tableaus qui stockent le lieu de depart et la destination finale
	// Ensuite, il detruit tous les TrajetSimples stockes dans ce TrajetCompose
	delete [] Depart;
	delete [] Arrivee;
	int i;
	for(i=0;i<NombreTrajets;i++){
	delete TrajetsSimples[i];
	}
	delete [] TrajetsSimples;
}//----- Fin de M��thode
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protected

//------------------------------------------------------- Methodes privees

