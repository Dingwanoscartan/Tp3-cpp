/*************************************************************************
TrajetSimple  -  description
-------------------
debut                : 20/11
copyright            : (C) 2019 par Muye HE, Tuoyuan TAN
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ------
#if ! defined (TRAJETSIMPLE_H)
#define TRAJETSIMPLE_H
#include <fstream>
//--------------------------------------------------- Interfaces utilisees
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// Permet de creer un TrajetSimple et  de l'afficher
//------------------------------------------------------------------------
class TrajetSimple:public Trajet 
{
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Methodes publiques
	public :
		TrajetSimple(char * DEP, char * ARR, char * MODE);
		// Mode d'emploi :
		// constructeur de TrajetSimple qui prend DEP(lieu de depart), ARR(la destination) et MODE(le moyen de transport ) en parametres
		//
		TrajetSimple();
		// Mode d'emploi :
		// constructeur par defaut qui ne fait rien et qui n'a pas de parametres
		//
		~TrajetSimple ();
		// Mode d'emploi :
		// destructeur de TrajetSimple	
		//
		void Afficher ();
		// Mode d'emploi :
		// methode qui affiche tous les information d'un TrajetSimple
		//

		int isTrajetCompose();
		// Mode d'emploi :
		// methode qui affiche les information d'un Trajet
		// Contrat :
		//


		void Sauvegarder(fstream & sortie);
		// Mode d'emploi :
		// methode qui sauvegarde tous les information d'un TrajetSimple dans un flux
		//
		
		//---------------------------------------------------- Attributs publiques
		char * Mode;
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
#endif // TrajetSimple_H


