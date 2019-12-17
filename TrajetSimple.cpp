/*************************************************************************
TrajetSimple  -  description
-------------------
debut                : 20/11
copyright            : (C) 2019 par Muye HE, Tuoyuan TAN
e-mail               : $EMAIL$
*************************************************************************/
//---------- R��alisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst��me
#include <iostream>
using namespace std;
#include <cstring>
#include <fstream>
//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M��thodes publiques
TrajetSimple::TrajetSimple(char * DEP, char * ARR, char * MODE):Trajet(DEP, ARR),Mode(MODE)
{
	//Algorithme :
	//Depart =  DEP;
	//c = ARR;
	//Mode = MODE;
}//----- Fin de M��thode

TrajetSimple::TrajetSimple():Trajet(){}
	// constructeur par defaut qui ne fait rien et qui n'a pas de parametres

void TrajetSimple::Afficher()
{
	//Algorithme :
	cout << "de " << Depart << " a " << Arrivee << " en " << Mode << "\r\n";
}//----- Fin de M��thode


void TrajetSimple::Sauvegarder(fstream & sortie){
//Algorithme :
	sortie << "0 " << Depart << " " << Arrivee << " " << Mode << endl;
}

TrajetSimple::~TrajetSimple()
{
    //destructeur qui detruit ces trois tableaus de maniere explicite
	delete [] Depart;
	delete [] Arrivee;
	delete [] Mode;
}//----- Fin de M��thode

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protected

//------------------------------------------------------- Methodes privees


