/*************************************************************************
Trajet  -  description
-------------------
debut                : 20/11
copyright            : (C) 2019 par Muye HE, Tuoyuan TAN
e-mail               : $EMAIL$
*************************************************************************/
//---------- R¨¦alisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst¨¨me

#include <iostream>
#include<stdio.h>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M¨¦thodes publiques

Trajet::Trajet(char * DEP, char * ARR):Depart(DEP),Arrivee(ARR){
//Algorithme :
//this->Depart = DEP;
//this->Arrivee = ARR;
}//----- Fin de M¨¦thode

Trajet::Trajet(){
//Algorithme :
//constructeur vide
}//----- Fin de M¨¦thode

void Trajet::Afficher(){
//Algorithme :	
	cout<<"Trajet de "<<Depart<<" a "<<Arrivee<<endl; 
}//----- Fin de M¨¦thode

Trajet::~Trajet(){
//Algorithme :	
//destructeur
}//----- Fin de M¨¦thode


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protected

//------------------------------------------------------- Methodes privees
 
