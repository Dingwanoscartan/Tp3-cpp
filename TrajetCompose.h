/*************************************************************************
TrajetCompose  -  description
-------------------
debut                : 20/11
copyright            : (C) 2019 par Muye HE, Tuoyuan TAN
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ------
#if ! defined (TRAJETCOMPOSE_H)
#define TRAJETCOMPOSE_H
#include <cstring>
#include <fstream>
using namespace std;
//--------------------------------------------------- Interfaces utilisees
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// Permet de creer un TrajetCompose et  de l'afficher
//------------------------------------------------------------------------
class TrajetSimple;
class TrajetCompose: public Trajet
{
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Methodes publiques
	public :
		TrajetCompose(char * DEP, char * ARR, TrajetSimple** LesTrajets, const int Nombre);
		// Mode d'emploi :
		// constructeur de TrajetCompose qui prend DEP(lieu de depart), ARR(la destination), LesTrajets (un tableau qui stocke tous les TrajetSimples) et Nombre (le nombre de TrajetSimples) en parametres
		//
		TrajetCompose();
		// Mode d'emploi :
		// constructeur par defaut qui ne fait rien et qui n'a pas de parametres
		//
		~TrajetCompose ();
		// Mode d'emploi :
		// destructeur de TrajetCompose	
		//
		void Afficher ();
		// Mode d'emploi :
		// methode qui affiche tous les information d'un TrajetCompose et les TrajetSimples associes
		//

		void Sauvegarder(fstream & sortie);
		// Mode d'emploi :
		// methode qui sauvegarde tous les information d'un TrajetCompose dans un flux
		//
		
		
		//---------------------------------------------------- Attributs publiques
		TrajetSimple ** TrajetsSimples;
        int NombreTrajets;
        
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
#endif // TrajetCompose_H
