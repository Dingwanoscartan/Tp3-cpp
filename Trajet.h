/*************************************************************************
Trajet  -  description
-------------------
debut                : 20/11
copyright            : (C) 2019 par Muye HE, Tuoyuan TAN
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ------
#if ! defined ( TRAJET_H )
#define TRAJET_H
//--------------------------------------------------- Interfaces utilisees
#include <cstring>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Permet de creer un Trajet et  de l'afficher
//------------------------------------------------------------------------

class Trajet{

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Methodes publiques
public:
	Trajet (char * DEP,char * ARR);
	// Mode d'emploi :
	// constructeur de Trajet qui prend DEP et ARR en parametres
	// Contrat :
	//

	Trajet();
	// Mode d'emploi :
	// constructeur de Trajet par defaut
	// Contrat :
	//

	virtual ~Trajet();
	// Mode d'emploi :
	// destructeur de Trajet
	// Contrat :	
	//
	virtual void Afficher();
	// Mode d'emploi :
	// methode qui affiche les information d'un Trajet
	// Contrat :
	//

	virtual void Sauvegarder(fstream & sortie);
	// Mode d'emploi :
	// methode qui sauvegarde les information d'un Trajet dans un flux
	// Contrat :
	//

//---------------------------------------------------- Attributs publiques
	char * Depart;
    char * Arrivee;
//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Methodes protected

private:
//------------------------------------------------------- Methodes prives

protected:
//----------------------------------------------------- Attributs protected

private:
//------------------------------------------------------- Attributs prives

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes prives

//----------------------------------------------------------- Types prives
};
//----------------------------------------- Types dependants de <Trajet.h>
#endif // TRAJET_H
